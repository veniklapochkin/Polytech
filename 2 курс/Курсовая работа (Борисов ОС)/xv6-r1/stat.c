#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[]){ // argc кол-во эл-ов массива argv- массив слов 
	struct stat s;
	if (argc != 2)
		printf(0,"stat: incorrectly set parameters\n");
	else{
		int i = open(argv[1], O_RDONLY);
		if (i < 0)
			printf(0,"stat: cannot open %s\n",argv[1]);
		else
			if (fstat(i, &s) < 0)
				printf(2,"stat: cannot stat %s\n",argv[1]);
			else{
				printf(0," Type: ");
				if (s.type == T_DEV)
					printf(0,"special device: %d", s.type);
				else
					if (s.type == T_DIR)
						printf(0,"directory: %d",s.type);
					else
						printf(0,"file: %d",s.type);
				printf(0,"\n File system's disk device: %d\n",s.dev);
				printf(0," Inode number: %d\n",s.ino);
				printf(0," Number of links to file: %d\n",s.nlink);
				printf(0," Size: %d",s.size);
				printf(0," bytes\n");
			}
		close(i);
	}
	exit();
}
