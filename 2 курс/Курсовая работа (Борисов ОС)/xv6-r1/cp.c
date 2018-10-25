#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"
int copyFile(int fdr, int fdw)
{
	char buf[512];
	int r,w;
	while ((r = read(fdr, buf, sizeof(buf))) > 0)
	{
		w = write(fdw, buf, r);
		if (w != r || w < 0)	
			return -1;
	}
	if (r < 0)	
		return -1;
	else
		return 0;
}
void copy(char *frst, char *scnd)
{
	struct stat temp;
	int fdr = open(frst, O_RDONLY), fdw;
	if (fdr < 0)
		printf(0,"cp: fail of the opening %s\n", frst);
	else
	{
		if (fstat(fdr, &temp) < 0)
			printf(0,"cp: fail of the review statistic %s\n", frst);
		else
		{
			if (temp.type != T_DIR)
			{
			
				fdw = open(scnd, O_CREATE | O_WRONLY);
				if (fdw < 0)
					printf(1,"cp: fail of the opening %s\n", scnd);
				else
					if (copyFile(fdr,fdw) < 0)	
						printf(0,"cp: copy error %s to %s\n", frst, scnd);
					else
						return;
				close(fdw);
			}
			else
			{
				if (mkdir(scnd) < 0)
				{
					fdw = open(scnd, O_RDONLY);
					if (fdw < 0)
						printf(1,"cp: fail of the opening or creating %s\n", scnd);
					else
					{
						fstat(fdw, &temp);
						if(temp.type != T_DIR)
							printf(1,"cp: %s is not a directory\n", scnd);
					}
					close(fdw);
				}
				else
				{		
					if(strlen(frst) + 1 + DIRSIZ + 1 > 512)
						printf(1, "(cp: copied path is too long\n");
					else
					{
						if(strlen(scnd) + 1 + DIRSIZ + 1 > 512)
							printf(1, "cp: created path is too long\n");
						else
						{
							char *r, *w;
							struct dirent dirr;
							r = frst + strlen(frst);
							w = scnd + strlen(scnd);
							*r++ = '/';
							*w++ = '/';
							while(read(fdr, &dirr, sizeof(dirr)) == sizeof(dirr))
							{
								if(dirr.inum == 0 || strcmp(dirr.name,".") == 0 || strcmp(dirr.name,"..") == 0)
									continue;
								memmove(r, dirr.name, DIRSIZ);
								memmove(w, dirr.name, DIRSIZ);
								r[DIRSIZ] = 0;
								w[DIRSIZ] = 0;
								copy(frst, scnd);
							}
							close(fdr);
							return;
						}
					}
				}
			}
		}
	}
	close(fdr);
	exit();
}
int main(int argc, char *argv[])
{
	if(argc != 3)
		printf(0,"cp: incorrectly set parameters\n");
	else
	{
		char frst[512], scnd[512];
		strcpy(frst, argv[1]);
		strcpy(scnd, argv[2]);
		copy(frst, scnd);
	}
	exit();
}
