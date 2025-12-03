#ifndef SIMPLETEXTGENERATOR_H 
#define SIMPLETEXTGENERATOR_H

#include <string>
#include <vector>
#include <map>
#include "TextGenerator.h"
using namespace std;

class SimpleTextGenerator: public TextGenerator{
    map<string,vector<string>> stats;
public:
    void trainFromText(string trainingText) override;
    void trainFromFIle(string filename);
    string generate(string startWords, int numWords);
};

#endif