#ifndef __INTERN_H
#define __INTERN_H

#include "employee.h"

class Intern : public Employee {
    string Majors;                  // Chuyên ngành đang học
    int Semester;                   // Học kì đang học
    string University;              // Tên trường đang học
public:
    void insertData();
    void showInfo();
    void setMajors(const string&);
    void setSemester(const int&);
    void setUniversity(const string&);
    string getMajors();
    int getSemester();
    string getUniversity();
};

#endif // !__INTERN_H
