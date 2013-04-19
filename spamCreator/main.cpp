#include <QtCore/QCoreApplication>
#include <iostream>
#include "direxplorer.h"




using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Utworzenie obiektu eksplorera
    DirExplorer *d = new DirExplorer();

    //Ustawienie �cie�ki i sprawdzenie, czy istnieje
    d->setPath("C:\\");
    if(d->open_success())
    {
     cout << "Initialize success" << endl;
     d->load();
    }
    else
    {
     cout << "Initialize failure" << endl;
    }


    //Usuni�cie obiektu eksplorera
    delete(d);

    return a.exec();
}
