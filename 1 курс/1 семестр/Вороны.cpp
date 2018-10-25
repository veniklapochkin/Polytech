	
// Вороны
    #include <iostream>
    #include <conio.h>
     
    using namespace std;
     
    int main(void)
    {
		setlocale(0,"");
        // Ворон -  5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,26,27,28,29,30
        // Вороны -  2,3,4,22,23,24
        // Ворона - 1,21,31,41,51,61,71,81,91
        int crows;
        cin >> crows;
        if ((crows<1)||(crows>99)) cout << "Wrong value\n";
        else
        {
            if ((crows%10==5)||(crows%10==6)||(crows%10==7)||(crows%10==8)||(crows%10==9)||(crows%10==0)||((crows>10)&&(crows<20))) cout << crows << " voron\n";
            else (crows%10==1) ? cout << " ворона\n" : cout << crows << " вороны\n";
        }
        getch();
    }


