#ifndef GRADUATIONDAO_H
#define GRADUATIONDAO_H


#include <iostream>
#include <string>
#include <map>
#include "student.h"
using namespace std;


class GraduationDao {
        int year{2023};
        map<int, Student> students;
    public:
        explicit GraduationDao(int year) : year(year) {}
        void enrollStudents(const string &filename);//kesz
        void printstudents(){
            for(const auto& pair : students){cout<<pair.second<<endl;}
        }
        void readGradesSubject(const string &subject, const string &filename);//kesz
        int numEnrolled() const{return students.size();}
        int numPassed() const;
        Student findById(int id) const; //throws out_of_range exception for nonexistent id
        double getAverageBySubject(const string &subject) const;
};




#endif