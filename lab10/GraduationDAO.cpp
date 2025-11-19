#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "student.h"
#include "GraduationDAO.h"
using namespace std;

void GraduationDao::enrollStudents(const string &filename){
    
    ifstream fin(filename);
    if (!fin.is_open()){
        cout<<"nem lehet megynitniiiii"<<filename<<endl;
        return;
    }

    string line;
    while(getline(fin,line)){
        if(line.empty()){
            continue;
        }
    }
    stringstream ss(filename);
    int id;
    string lastName, firstName;
    ss>> id >> lastName >> firstName;
        cout<<id<<lastName<<endl;
        students.emplace(id, Student(id, firstName, lastName));

    fin.close();
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename){
    ifstream fin(filename);
    if (!fin.is_open()){
        cout<<"nem lehet megynitniiiii"<<filename<<endl;
        return;
    }

    string line;
    while(getline(fin,line)){
        if(line.empty()){
            continue;
        }
    }

    
    int id;
    double grade;
    while(fin >> id >> grade){
        students[id].addGrade(subject,grade);}


    


    fin.close();
}

//int GraduationDao::numPassed() const{
    

