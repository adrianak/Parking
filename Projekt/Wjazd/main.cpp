
#include "Wjazd.h"
using namespace std;

void Wait()
{
    for(int i=0;i<100000000;i++)
    {

    }
    return;
}

int main()
{
    CWjazd Dostep;
    for(;;){
    string str=Dostep.getBlacha();
    Dostep.wpiszWjazd(str);
    Dostep.PrintTicket();
    Dostep.openGate();
    Wait();
    Dostep.closeGate();
    }
    return 0;
}
