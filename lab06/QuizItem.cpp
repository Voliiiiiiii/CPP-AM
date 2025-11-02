#include <iostream>
#include <vector>
#include <algorithm>
#include "QuizItem.h"
using namespace std;

int QuizItem::counter = 0;

QuizItem::QuizItem(string question, vector<string> answers, int correct_answ)
    :question(question), answers(answers), correct_answ(correct_answ){
    question_id = counter++;
}

ostream& operator<<(ostream& os,const QuizItem& item){
    os<<item.question<<endl;
    int counter = 0;
    for_each(item.answers.begin(),item.answers.end(), [&os, &counter](const string& answer){
        os<<"\t"<<counter<<". - "<<answer<<endl;
        counter++;
    });
    return os;
}