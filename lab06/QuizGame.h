#ifndef QUIZGAME_H
#define QUIZGAME_H

#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
using namespace std;

class QuizGame{
    private:
        User& user;
        Quiz& quiz;
    public:
        QuizGame(User& user, Quiz& quiz):user(user),quiz(quiz){}
        ~QuizGame()=default;
        void run();
};

#endif