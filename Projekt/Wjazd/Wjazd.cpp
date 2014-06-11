#include "Wjazd.h"

using namespace std;
CWjazd::CWjazd()
{
    string tmpstr="Wjazdy.txt";
    Wjazdy.setFile(tmpstr);
    Wjazdy.setSizeREG(32);
}

string CWjazd::getBlacha()
{//w polsce tablice maja 7-8 znakow
    string tmpstr;
    cout<<"Wpisz numer swojej rejestracji 7-8 znaków"<<endl;
    for(;;)
    {
    cin>>tmpstr;
    if((tmpstr.size()>6)&&(tmpstr.size()<9))
    {
        if(tmpstr.size()==7)
            tmpstr+="0";
        return tmpstr;
    }
    }
}

bool CWjazd::wpiszWjazd(string str)//str to numer rejestracji
{
    char buffer[13];
    string tmpstr=str;
    time_t czas;
    struct tm * ptr;
    time( & czas );
    ptr = localtime( & czas );
    strftime (buffer,13,"%Y%m%d%H%M",ptr);

    str+=buffer;
    str+="000000000000";

    Wjazdy.PushReg(str);
    return false;
}

