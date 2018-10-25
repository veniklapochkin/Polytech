// иллюстрирующая программа для fmin.cpp
# include <stdio.h>
# include "fmin.h"
# include <math.h>

double FunFmin(double z)
{  
	return (1.5+sin(z));
}

void main( void )
	
	 
	{  
		double C;
		double A=2;
		double B=6;
		double Error;
		double TOL=1e-8;
		int flag;
        

		C=fmin(A,B,FunFmin,TOL,Error,flag);

		
	printf("%f\n", C);
}

