CAdmin()
{
    string tmpstr="PstObslg.txt";
    PstObslg.setFile(tmpstr);
    PstObslg.setSizeREG(32);//to samo co wjazdy

    tmpstr="KlienciBASE.txt";
    Klienci.setFile(tmpstr);
    Klienci.setSizeREG(14);//8na blache 6na pin?    bbbbbbbbpppppp

    tmpstr="Wjazdy.txt";
    Wjazdy.setFile(tmpstr);
    Wjazdy.setSizeREG(32);//8na blache 12data wjazdu 12datawyjazdu      tablica0YYYYMMDDhhmmYYYYMMDDhhmm
}
