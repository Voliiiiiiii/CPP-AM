#include <iostream>
#include <string>
#include "FileSystemItem.h"
#include "File.h"
using namespace std;


void File::display(ostream& os, int depth)const {
    os<<this<<endl;
}