#include <QtCore/QCoreApplication>
#include <iostream>
#include "direxplorer.h"
#include "directorynode.h"



using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Utworzenie obiektu eksplorera
    DirExplorer *d = new DirExplorer();

    //Ustawienie œcie¿ki i sprawdzenie, czy istnieje
    d->setPath("C:\\");
    if(d->open_success())
    {
     cout << "Initialize success" << endl;
     d->load();
     vector<string> *dict =d->getDictonaries();
     if(dict != NULL)
     {
         for(uint i = 0; i < dict->size(); i++)
         {
             cout << dict->at(i) << endl;
         }
        delete dict;
     }
    }
    else
    {
     cout << "Initialize failure" << endl;
    }


    //Usuniêcie obiektu eksplorera
    delete(d);

    //Sprawdzanie struktury
    DirectoryNode *dnode = new DirectoryNode("C:\\");
    delete dnode;


    return a.exec();
}
