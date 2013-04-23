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


    //Obs�uga wyj�tku - z�a �cie�ka
    // * �cie�ka nie istnieje
}

DirectoryNode::~DirectoryNode()
{
    //Zwalnianie pami�ci
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
    //Wyj�tek, je�eli nie zainicjowano
    return this->path;
}

std::string DirectoryNode::getDirectoryName()
{
    //Wyj�tek je�li nie zainicjowano
    return this->name;
}

