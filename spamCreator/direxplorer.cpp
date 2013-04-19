#include "direxplorer.h"

//Inicjalizacja wartoœci pustych
DirExplorer::DirExplorer()
{
    entry = NULL;
    dp = NULL;
    initialized = false;
    childs_loaded = false;
}


//Zamkniêcie deskryptora
DirExplorer::~DirExplorer()
{
 if(initialized)
    closedir(dp);
}

//Ustawienie œcie¿ki startowej
bool DirExplorer::setPath(const char* path)
{
   this->path = path;

   dp = opendir(path);
   if (dp == NULL) { return false; }
   else { initialized = true; return true;  }
}

//Czy poprawnie otwarto wskazany katalog
bool DirExplorer::open_success()
{
  if(initialized == false)
  {
        return false;
  }
  else
  {
        return true;
  }
}


bool DirExplorer::load()
{

    if(childs_loaded)
    {
        return false;
    }
    else
    {
        childs_loaded = true;
        //wczytanie wszystkich plików i folderów z katalogu
        while((entry = readdir(dp)))
            childs.push_back(entry->d_name);
        return true;
    }
}

vector<std::string>*  DirExplorer::getDictonaries()
{
    if(this->childs_loaded == false) return NULL;
    vector<string> *dictonaries = new vector<string>();
    for(unsigned int i = 0; i < childs.size(); i++)
    {
        if(((string)(childs[i])).find(".") == string::npos)
        {
            dictonaries->push_back(path+(childs[i])+"\\");
        }
    }
    return dictonaries;

}

vector<std::string>* DirExplorer::getFiles()
{
    if(this->childs_loaded == false) return NULL;
    vector<string> *files = new vector<string>();
    for(unsigned int i = 0; i < childs.size(); i++)
    {
        if(((string)(childs[i])).find(".") != string::npos)
        {
            files->push_back(path+(childs[i]));
        }
    }
    return files;

}




