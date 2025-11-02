#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <string>
#include <vector>
#include "QuizItem.h"
using namespace std;

class Quiz{
    private:
        static int quiz_counter;
        int quiz_id;
        string quiz_name;
        vector<QuizItem> questions;
        bool is_ready;
        
    public:
        Quiz(int id, string quiz_name);
        ~Quiz()=default;

        void addItem(const QuizItem& quizitem);
        void finalize();
        bool get_is_ready()const{ return is_ready;};
        friend void printquiz(const Quiz& quiz);
        string get_quiz_name()const{return quiz_name;}
        vector<QuizItem>& get_questions(){return questions;}
        int get_quiz_id()const{return quiz_id;}
};

#endif