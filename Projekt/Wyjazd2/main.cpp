#include <iostream>
#include "Wyjazd.h"

using namespace std;
void Wait()
{
    for(int i=0;i<10000000;i++)
    {

    }
}
int main()
{
    CWyjazd Dostep;
    string str;
    //for(;;)
    //{
        cout<<"Wprowadz numer rejestracji"<<endl;
        str=Dostep.waitFT();
    bool oplacono=Dostep.MoznaWyjechac(str);
    if(oplacono)
    {
        Dostep.openGate();
        Wait();
        Dostep.Przerzuc(str);
        Dostep.closeGate();
    }
    //}
    return 0;
}
