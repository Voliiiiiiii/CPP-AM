#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "SimpleTextGenerator.h"
using namespace std;


string cleanWord(const string &word){
    string res;
    for (char c : word) {
        c = tolower((unsigned char)c);
        if (isalpha((unsigned char)c)) {
            res += c;
        }
    }
    return res;
}

void SimpleTextGenerator::trainFromText(string trainingText){
    vector<string> words;
    stringstream ss(trainingText);
    string word;
    while(ss>> word){
        words.push_back(word);
    }
    for(int i = 0 ; i< words.size() -1 ;i++){
        string key = words[i] + " " + words[i+1];
        if(i+2 < words.size()){
            stats[key].push_back(words[i+2]);    
        }
        else{
            stats.insert({key,vector<string>()});
        }
        
    }
    for(auto pair : stats){
        cout<<pair.first << ": ";
        for(auto pairValue : pair.second){
            cout<< pairValue << " ";
        }
        cout<<endl;
    }
}

string SimpleTextGenerator::generate(string startWords, int numWords){
    string ss(startWords+" ");
    srand(time(0));
    for(int i= 0;i<numWords;i++){
        //cout<<"* "<<startWords<<endl;
        auto it = stats.find(startWords);
        if(it == stats.end()){
            return ss;
        }
        auto size = it->second.size();  
        
        if(size == 0){
            return ss;
        }
            int pos = rand() % size;
            ss += (it->second[pos] + " ");

        
        
       stringstream twoWord(startWords);
       string word2;
       twoWord >> word2 >> word2;
       startWords = word2 + " " + it->second[pos];


    }
    return ss;
}