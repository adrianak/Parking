//#ifndef _Gate_H_
//#define _GATE_H_
//#include "Gate.h"
//#endif

#ifndef _BAZA_H_
#define _BAZA_H_
#include "baza.h"
#endif

#ifndef _STRING_H_
#define _STRING_H_
#include <string.h>
#endif

#ifndef _CSTDLIB_
#define _CSTDLIB_
#include <cstdlib>
#endif

#ifndef _CTIME_
#define _CTIME_
#include <ctime>
#endif

#include <iostream>

class CWjazd
{
    //CBaza Klienci;
    CBaza Wjazdy;
    public:
    CWjazd();//
    //bool szukajKlienta(string);
    string getBlacha();//
    bool openGate(){cout<<"Brama Otwarta"<<endl; return true;}
    bool closeGate(){cout<<"Brama Zamknieta"<<endl; return true;}

    bool wpiszWjazd(string);//
    bool PrintTicket(){return true;}
};
