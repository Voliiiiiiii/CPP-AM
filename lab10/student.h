#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <map>
#include <string>
using namespace std;



class Student {
    private:
        static int counter;
        int id;
        string firstName;
        string lastName;
        map<string, double> grades;
        double average {0.0};
    public:
        Student()=default;
        Student(int id, const string &firstName, const string &lastName);//kesz
        Student(const string &firstName, const string &lastName);//kesz (magamnak mainhez)
        void addGrade(const string& subject, double grade);//kesz
        void computeAverage();//kesz

        const map<string, double> &getGrades() const{return grades;}
        const string &getFirstName()const{return firstName;}//kesz
        const string &getLastName() const{return lastName;}//kesz
        int getId() const{return id;}//kesz
        double getAverage() const{return average;}//kesz
        double getGrade(const string& subject) const{return grades.at(subject);}//kesz

        friend ostream& operator<<(ostream& os, const Student& student);
};


#endif