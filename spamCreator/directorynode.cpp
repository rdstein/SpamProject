#include "directorynode.h"

DirectoryNode::DirectoryNode(string path)
{
    this->path = path;
    success_open = false;

    //Dodanie nazwy folderu
        //Znalezienie ostatniego znaku / lub \

    int *index = new int;

    *index = -1;
    for(unsigned int i = path.size() -1 -1; i >= 0; i--)
    {
        if(path[i] == '/' || path[i] == '\\')
        {
            *index = i;
            break;
        }
    }

        //Odczytanie nazwy folderu
    if(*index != -1)
    {
        for(unsigned int i = (*index)+1; i < path.size()-1; i++)
        {
            this->name += path[i];
        }
    }

    delete index;


    //Obs³uga wyj¹tku - z³a œcie¿ka
    // * œcie¿ka nie istnieje
}

DirectoryNode::~DirectoryNode()
{
    //Zwalnianie pamiêci
    for(unsigned int i = 0; i < childs.size(); i++)
    {
        delete childs[i];
    }
}


void DirectoryNode::push(FileSystemNode *node)
{
    childs.push_back(node);
}

unsigned int DirectoryNode::size()
{
    return childs.size();
}

std::string DirectoryNode::getPath()
{
    //Wyj¹tek, je¿eli nie zainicjowano
    return this->path;
}

std::string DirectoryNode::getDirectoryName()
{
    //Wyj¹tek jeœli nie zainicjowano
    return this->name;
}

