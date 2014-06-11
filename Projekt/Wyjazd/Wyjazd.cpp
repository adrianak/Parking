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
    cout<<"Obliczanie Oplaty"<<endl;
    return 10;
}

bool PoborOplaty(int)
{
    cout<<"Pobieranie Oplaty"<<endl;
    cout<<"Postuj darmowy"<<endl;
    return true;
}

 bool CWyjazd::Zaplac(string str)//tablica
 {
     string tmpstr;
     int kasa;

         tmpstr=Wyjazdy.GetReg(str,0,0);
         //cout<<tmpstr<<endl;

         if(tmpstr=="")
            return 0;

     //string i 000000000000
     char buffer[13];
        time_t czas;
        struct tm * ptr;
        time( & czas );
        ptr = localtime( & czas );
        strftime (buffer,13,"%Y%m%d%H%M",ptr);
    kasa=Oplata(tmpstr.substr(8,12),buffer);
    if(PoborOplaty(kasa))
    {
        cout<<tmpstr.substr(0,20)+buffer<<" "<<tmpstr<<endl;
        cout<<Wyjazdy.PushReg(tmpstr.substr(0,20)+buffer,tmpstr)<<endl;
        return 1;
    }
    else
    return 0;
 }
