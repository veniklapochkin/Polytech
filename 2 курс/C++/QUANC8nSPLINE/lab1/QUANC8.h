void quanc8(double(*FUN)(double),double A,double B,double ABSERR,double RELERR,double *RESULT,double *ERREST,int *NOFUN,double *FLAG);
/*
FUN ��� ������������-�������, ����������� �������� ��������������� ������� f (�);
�, B - ������ � ������� ������� ��������������;
ABSERR � RELERR - ������� ���������� � ������������� ������������.
RESULT - �������� ���������, ������������ ����������;
ERREST - ������ �����������, ����������� ����������
NOFUN - ���������� ���������� ��������������� ������� f(x), �������������� ��� ��������� ����������;
FLAG - ��������� ���������� ����������.
*/