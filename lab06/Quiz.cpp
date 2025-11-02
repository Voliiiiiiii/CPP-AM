#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"

using namespace std;

int Quiz::quiz_counter=0;

Quiz::Quiz(int id, string quiz_name):quiz_id(quiz_counter++), quiz_name(quiz_name), is_ready(false){
}

void Quiz::addItem(const QuizItem& quizitem){
    if(is_ready){
        cout<<"Quiz is already finished, cant add no more"<<endl;
        return;
    }
    questions.push_back(quizitem);
    
}
void Quiz::finalize(){
    is_ready=true;
}
void printquiz(const Quiz& quiz){
    cout<<"Quiz Name: "<<quiz.quiz_name<<endl;
    for(const auto& item: quiz.questions){
        cout<<item<<endl;
    }
}