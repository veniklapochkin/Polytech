#include "header.h"
int main()
{
	char realnum[N], ans[N];
	setlocale (0, "");
	cout<<"Введите вещественное число \n";
	cin>>realnum;
	int i;
	char x;
	for (i=0; realnum[i]!='\0'; i++);
	realnum[i]=0;
	x=real(realnum, ans);
	if (x==1) cout<<ans<<'\n';
	else cout<<"Введено не вещественное число";
	return 0;
}