#ifndef DIREXPLORER_H
#define DIREXPLORER_H
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <vector>

using namespace std;


class DirExplorer
{
  //Dane pobrane
  vector<string> childs;
  string path;

  //Techniczne
  struct dirent *entry; //poszczeg�lny plik/folder ?
  DIR *dp; //struktura do zarz�dzania �cie�kami
  bool initialized; //czy zainicjowano
  bool childs_loaded;


  private:

  public:


  DirExplorer();
  ~DirExplorer();

 //Ustawienie �cie�ki
 bool setPath(const char* path);


 //Czy otwarto poprawnie folder
 bool open_success();

 bool load();

 vector<string>* getDictonaries();

 vector<string>* getFiles();




};

#endif // DIREXPLORER_H
