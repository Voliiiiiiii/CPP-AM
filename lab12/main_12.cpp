#include <iostream>
#include "SimpleTextGenerator.h"
using namespace std;

int main() {
    SimpleTextGenerator tg;
    tg.trainFromText(" Now is not the time for sleep, now is the time for party!");

    for(int i = 0; i < 10 ; ++i){
        cout<<tg.generate("time for",6)<<endl;
    }
    return 0;
}