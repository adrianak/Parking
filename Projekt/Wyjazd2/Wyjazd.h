//#ifndef _Gate_H_
//#define _GATE_H_
//#include "Gate.h"
//#endif

#ifndef _BAZA_H_
#define _BAZA_H_
#include "baza.h"
#endif

#ifndef _CSTDLIB_
#define _CSTDLIB_
#include <cstdlib>
#endif

#ifndef _CTIME_
#define _CTIME_
#include <ctime>
#endif

class CWyjazd
{
    CBaza Klienci;
    CBaza Wyjazdy;
    public:
    CWyjazd();//

    bool openGate(){return true;}
    bool closeGate(){return true;}

    string waitFT();//
    bool checkT(string);//
    string szukajKlienta(string);//
    bool MoznaWyjechac(string);
    //bool wpiszWyjazd(string);
    bool Zaplac(string);
    bool Przerzuc(string);
};
