#include <iostream>
#include <string>
#include <map>
#include "student.h"
#include "GraduationDAO.h"
using namespace std;


int main() {
    Student onmagam("Voloncs", "Botond");
    onmagam.addGrade("math", 9.55);
    onmagam.addGrade("hungarian", 6.77);
    onmagam.addGrade("romanian",6.55);
    cout<<onmagam;

    string subjects[]{"math", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");

    dao.printstudents();
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
    dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    //cout <<"Number of passed students: " << dao.numPassed() << endl;

    

    return 0;
}