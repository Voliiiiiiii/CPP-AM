#ifndef USER_H
#define USER_H

#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include <map>
using namespace std;

class User{
    private:
        int id;
        string user_name;
        map<int,int> results;
    public:
    User(int id, string user_name):id(id),user_name(user_name){}
    ~User()=default;
    void add_result(int quiz_id, int precentage);
    string get_name()const{return user_name;}
    void print_results()const;
};

#endif