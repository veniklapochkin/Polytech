#include "Rectangle.h"
int comparisonTR(Triangle ob1, Rectangle ob2)
{
	float sT, sR, d;
	d = (ob1.lab + ob1.lbc + ob1.lac) / 2;
	sT = sqrt(d*(d - ob1.lab)*(d - ob1.lbc)*(d - ob1.lac));
	sR = ob2.len_*ob2.wid_;
	if (sT > sR) return 0;
	if (sT < sR) return 1;
	return 2;
}