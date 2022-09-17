#ifndef __FRESHER_H
#define __FRESHER_H

#include "employee.h"

class Fresher : public Employee {
    string Graduation_date;         //Thời gian tốt nghiệp
    string Graduation_rank;         // Xếp loại tốt nghiệp
    string Education;               //truong tot nghiep
public:
    void insertData();
    void showInfo();
    void setGraduationDate(const string&);
    void setGraduationRank(const string&);
    void setEducation(const string&);
    string getGraduationDate();
    string getGraduationRank();
    string getEducation();
};

#endif // !__FRESHER_H
