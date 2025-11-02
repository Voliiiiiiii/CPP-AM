#include <iostream>
#include <stdexcept>
#include <map>
#include "User.h"
using namespace std;

void User::add_result(int quiz_id, int precentage){
    if(precentage<0||precentage>100){
        throw out_of_range("precentage over or under limitation");
    }
    auto it = results.find(quiz_id);
    if(it != results.end() && precentage > it->second){//KAPTA MEG AZ IDT
        it->second = precentage;
    }else{
        results[quiz_id]=precentage;
    }
}

void User::print_results()const{
    cout<<"Results for user: "<<user_name<<endl;
    for(const auto& result: results){
        cout<<"\tQuiz ID: "<<result.first<<"\tScore: "<<result.second<<"%"<<endl;
    }
}