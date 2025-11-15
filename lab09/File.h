#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include "FileSystemItem.h"
using namespace std;

class File: public FileSystemItem{
    public:
        File(const string& name,long size):FileSystemItem(name,size){}
        ~File()=default;
        long getSize()const override{return size;}
        void display(ostream& os = cout, int depth = 0)const override;
        FileSystemItem* clone() const override{
            return new File(*this);
        }
};

#endif