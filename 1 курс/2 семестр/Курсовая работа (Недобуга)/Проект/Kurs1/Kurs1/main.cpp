#include <iostream>
#include "stringl.h"
#include "Base.h"

using namespace std;

int main (int argc, char **argv)
{
	try
	{
		Base *B = new Base [4];
		ReadFile(B,4);
		ShowBase(B,4);
		if (B[0]>B[1])
			cout<<B[0]<<endl;
		else
			cout<<B[1]<<endl;
	}
	catch (const char *c)
	{
		cerr<<c;
	}
	system("pause");
	return 1;
}