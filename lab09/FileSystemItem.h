#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <iostream>
#include <string>
using namespace std;


class FileSystemItem{
    protected:
        string name;
        long size;

    public: 
        FileSystemItem(const string& name,long size=0):name(name),size(size){}
        ~FileSystemItem()=default;
        virtual long getSize()const=0;
        virtual void display(ostream& os = cout, int depth = 0)const = 0;
        virtual FileSystemItem* clone() const = 0;
        
        friend ostream& operator<<(ostream& os, const FileSystemItem& item){
            os<<item.name<<"("<<item.size << " bite)" <<endl;
            return os;
        }
        bool operator<(const FileSystemItem& other){return name <other.name;}
};

#endif