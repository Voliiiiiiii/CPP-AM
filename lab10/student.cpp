#include <iostream>
#include <string>
#include <map>
#include "student.h"
using namespace std;

int Student::counter=0;

Student::Student(int id, const string &firstName, const string &lastName):id(id),firstName(firstName),lastName(lastName){
    computeAverage();
}

Student::Student(const string &firstName, const string &lastName):id(counter++),firstName(firstName),lastName(lastName){
    computeAverage();
}

void Student::addGrade(const string& subject, double grade){
    grades[subject]=grade;
    computeAverage();
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }

    double sum = 0.0;

    for (const auto& pair : grades) {
        sum += pair.second; 
    }

    average = sum / grades.size();
}

ostream& operator<<(ostream& os, const Student& student){
    os<<"id-" << student.id <<" "<<student.firstName<<" "<<student.lastName<<", --GRADES-- ";
    for(const auto& pair : student.grades){
        os<<pair.first<<"("<<pair.second<<"), ";
    }
    os<< "AVERAGE("<<student.average<<")" <<endl;
    return os;
}

