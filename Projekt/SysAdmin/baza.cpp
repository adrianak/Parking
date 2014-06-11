#ifndef _BAZA_H_
#define _BAZA_H_
#include "baza.h"
#endif

using namespace std;

CBaza::CBaza()
{
    fnazwa="REGbasePLIK.txt";
    sizeREG=10;
};

bool CBaza::setFile(string str)
{
    fnazwa=str;
    return true;
}

bool CBaza::setSizeREG(int nsize)
{
    sizeREG=nsize;
    return true;
}

bool CBaza::Open()
{
    //cout<<"Open: "<<fnazwa<<endl;
    plik.open(fnazwa.c_str(),fstream::in | fstream::out);
    if(plik)
    cout<<"Otwarto"<<endl;
    else
    cout<<"Nie Otwarto"<<endl;
    if(plik)
        return true;

    return false;
}

bool CBaza::Close()
{
    cout<<"Close"<<endl;
    plik.seekg (0, plik.beg);
    plik.clear();
    if(plik)
        plik.close();

    if(!plik)
        return true;

    return false;
}

string CBaza::GetReg(int Numer)
{
    Open();
    char* str=new char[sizeREG+1];
    Numer=Numer*sizeREG;
    plik.seekg(Numer);
    if(!plik.eof())
    {
        plik.get(str,sizeREG+1);
        buffor=str;
        //cout<<"GetReg"<<str<<endl;
    }
    delete str;
    Close();
    return buffor;
}


string CBaza::GetReg(string szukane,int Numer,int przesuniecie)
{
    Open();
    char* str=new char[sizeREG+1];
    char* str2=new char[szukane.size()+1];
    Numer=Numer*sizeREG;


    //plik.seekg(Numer);

    //cout<<fnazwa<<endl;
    //cout<<plik.eof()<<endl;
    for(;;)
    {
          //  if(Numer>100)
          //      break;
        plik.seekg (0, plik.beg);
        plik.seekg(Numer);
        Numer=Numer+sizeREG;
        //cout<<Numer<<endl;
        //cout<<plik.eof()<<endl;
        if(plik.eof())
        {
            Close();
            delete str;
            delete str2;
            return buffor="";
        }
        //cout<<"szukanie: "<<plik.eof()<<" "<<(int)plik.tellp()<<endl;
        plik.get(str,sizeREG+1);
        //cout<<szukane<<" "<<str<<endl;
        if(str[przesuniecie]==szukane[0])
        {
            for(int i=1;i<=szukane.size();i++)
            {
                if(str[przesuniecie+i]==szukane[i])
                {
                    //cout<<i<<" "<<szukane.size()<<endl;
                    if(i==szukane.size()-1)
                    {
                        Close();
                        buffor=str;
                        delete str;
                        delete str2;
                        //cout<<buffor;
                        return buffor;
                    }
                    //cout<<str[przesuniecie+i]<<" "<<szukane[i]<<endl;
                    continue;
                }
                else
                   {
                        break;
                   }
            }
        }
    }
    Close();
    delete str;
    delete str2;
    return buffor="";
    }


bool CBaza::PushReg(string str)
{
    Open();
    plik.seekg(0,plik.end);

    //cout<<"Push"<<str<<endl;
    plik<<str;
    Close();
    return true;
}

bool CBaza::PushReg(string str,int Numer)
{
    Open();
    Numer=Numer*sizeREG;
    plik.seekg(Numer);
    if(!plik.eof())
    {
        plik<<str;
        //cout<<"GetReg"<<str<<endl;
    }
    Close();
    return true;
}

bool CBaza::PushReg(string str1,string str2)
{
    Open();
    int Numer=0;
    char* tmpstr=new char [sizeREG+1];
    for(;;)
    {
    plik.seekg (0, plik.beg);
    plik.seekg(Numer);

        if(!plik.eof())
        {
            delete tmpstr;
            return false;
        }

    plik.get(tmpstr,sizeREG+1);
    if(tmpstr==str2)
    {
        plik.seekg (0, plik.beg);
        plik.seekg(Numer);
        plik<<str1;
        delete tmpstr;
        return true;
    }
    Numer+=sizeREG;
    }
    delete tmpstr;
    return false;
}
