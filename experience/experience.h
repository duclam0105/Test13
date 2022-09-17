#ifndef __EXPERIENCE_H
#define __EXPERIENCE_H

#include "employee.h"

class Experience : public Employee {
    int ExInYear;                   //Số năm kinh nghiệm
    string ProSkill;                //Kỹ năng chuyên môn
public:
    void insertData();
    void showInfo();
    void setEx(const int&);
    void setSkill(const string&);
    int getEx();
    string getSkill();
};

#endif // !__EXPERIENCE_H
