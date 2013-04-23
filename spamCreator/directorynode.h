#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H
#include <iostream>
#include <vector>
#include <filesystemnode.h>


using namespace std;

class DirectoryNode : FileSystemNode
{
private:
    vector<FileSystemNode*> childs;
    string path;
    string name;

    bool success_open;
public:
    DirectoryNode(string path);
    ~DirectoryNode();

    void push(FileSystemNode *node);
    unsigned int size();
    string getPath();
    string getDirectoryName();

};

#endif // DICTIONARYNODE_H
