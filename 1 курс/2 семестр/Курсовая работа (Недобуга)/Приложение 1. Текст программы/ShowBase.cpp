#include "Base.h"
#include <iomanip>
void ShowBase(Base* B, int I)
{
	cout<<endl
		<<"*********************************************"<<endl
		<<"*"<<setw(13)<<"Product"<<"|"<<setw(14)<<"Shop"<<"|"<<setw(14)<<"Price"<<"*"<<endl
		<<"*********************************************"<<endl;
	for (int i = 0; i<I; i++)
	{
		cout<<"*"<<B[i]<<"*"<<endl
			<<"*********************************************"<<endl;
	}
}