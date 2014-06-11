#include "Wyjazd.h"



CWyjazd::CWyjazd()
{
    string tmpstr="Wjazdy.txt";
    Wyjazdy.setFile(tmpstr);
    Wyjazdy.setSizeREG(32);

    tmpstr="KlienciBASE.txt";
    Klienci.setFile(tmpstr);
    Klienci.setSizeREG(32);
}

string CWyjazd::szukajKlienta(string str)//po rejestracji
{
    if(""==(Klienci.GetReg(str, 0, 0)))
        return Klienci.GetBuff();
    else
        return "";
}

string CWyjazd::waitFT()
{
    string tmpstr;
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

bool CWyjazd::checkT(string str)
{
    string tmpstr;
    string pin;
    if(""==(tmpstr=szukajKlienta(str)))
        return false;
    else
        {
            int k=0;
            for(;k==5;)
            {cout<<"podaj pin lub 000000 aby anulowac:"<<endl;
            cin>>pin;
            if(pin=="000000")
                return false;
            for(int i=0;i<7;i++)
            {
                if(pin[i]==tmpstr[8+i])
                {
                    k=5;
                    continue;
                }
                else
                {
                    k=0;
                    break;
                }
            }
            }
            return true;
        }
}



int Oplata(string wjazd,string wyjazd)
{
    return 10;
}

bool PoborOplaty(int)
{
    return true;
}

 bool CWyjazd::Zaplac(string str)//tablica
 {
     string tmpstr;
     int kasa;
     for(int i;;i++)
     {
         tmpstr=Wyjazdy.GetReg(str,0,0);
         cout<<tmpstr<<endl;
         cin>>kasa;
         if(tmpstr=="")
            return 0;

        if("000000000000"==tmpstr.substr(20))
            break;
        else
            continue;
     }
     //string i 000000000000
     cout<<"wyssal"<<endl;
     cin>>kasa;
     char buffer[13];
        time_t czas;
        struct tm * ptr;
        time( & czas );
        ptr = localtime( & czas );
        strftime (buffer,13,"%Y%m%d%H%M",ptr);
    kasa=Oplata(tmpstr.substr(8,12),buffer);
    if(PoborOplaty(kasa))
    {
        Wyjazdy.PushReg(tmpstr.substr(0,20)+buffer,tmpstr);
        return 1;
    }
    else
    return 0;
 }

bool CWyjazd::MoznaWyjechac(string str)
{
    //string str;
    int k;
    cout<<str<<endl;
    cin>>k;
    str=Wyjazdy.GetReg(str,0,0);
    cout<<str<<endl;
    cin>>k;
    if("000000000000"!=str.substr(20))
    return true;
    else
    return false;
}

bool CWyjazd::Przerzuc(string str)
{
    fstream plik;
    str=Wyjazdy.GetReg(str,0,0);
    Wyjazdy.PushReg("00000000000000000000000000000000",str);
    plik.open("Oplacone.txt",fstream::in | fstream::out);
    plik.seekg(0,plik.end);

    //cout<<"Push"<<str<<endl;
    plik<<str;
    plik.clear();
    plik.close();
    return true;
}
