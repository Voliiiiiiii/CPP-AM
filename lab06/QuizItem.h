#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class QuizItem{
    private:
        static int counter;
        int question_id;
        string question;
        vector<string> answers;
        int correct_answ;

        
    public:
        QuizItem(string question, vector<string> answers, int correct_answ);
        ~QuizItem()=default;
        friend ostream& operator<<(ostream& os,const QuizItem& item);
        int get_correct_answ()const{return correct_answ;}
};

#endif