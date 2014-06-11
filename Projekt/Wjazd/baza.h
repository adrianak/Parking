#ifndef _FSTREAM_H_
#define _FSTREAM_H_
#include <fstream>
#endif

#ifndef _STRING_H_
#define _STRING_H_
#include <string.h>
#endif

#include <iostream>


using namespace std;

class CBaza
{
    string buffor;
    fstream plik;
    string fnazwa;
    int sizeREG;
    bool Open();//
    bool Close();//
public:
    int GetSizeREG(){return sizeREG;}
    string GetBuff(){return buffor;}
    string GetReg(int);//
    string GetReg(string,int,int);//
    bool PushReg(string);//
    bool PushReg(string,int);//
    bool PushReg(string,string);//nowy string,stary string

    bool setSizeREG(int);
    bool setFile(string);
    CBaza();//
};
