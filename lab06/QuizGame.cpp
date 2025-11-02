#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"
using namespace std;

void QuizGame::run(){
    int score = 0;
    if(!quiz.get_is_ready()){
        cout<<"Quiz is not ready to play"<<endl;
        return;
    }

    cout<<"---------------STARTING QUIZ----------------: "<<endl;
    cout<<"Quiz Name: "<<quiz.get_quiz_name()<<"\t User name: "<< user.get_name()<< endl;
    cout<<"---------------------------------------------"<<endl;

    int myanswer;
    for(QuizItem item : quiz.get_questions()){
        cout<<item<<endl;
        cout<<"Your answer: "<<endl;
        cin>>myanswer;
        if(myanswer == item.get_correct_answ()){
            score++;
        }
    }
    int percentage = (score * 100) / quiz.get_questions().size();

    cout<<"You scored: "<<score<<" out of "<<quiz.get_questions().size()<<" ("<<percentage<<"%)"<<endl;
    user.add_result(quiz.get_quiz_id(), percentage);
}