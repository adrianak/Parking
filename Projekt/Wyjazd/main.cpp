#include <iostream>
#include "Wyjazd.h"

using namespace std;

int main()
{
    CWyjazd Dostep;
    for(;;){
        cout<<"wprowadz numer rejestracji podany przy wje�dzie"<<endl;
    string str=Dostep.waitFT();
    Dostep.Zaplac(str);

    }
    return 0;
}
