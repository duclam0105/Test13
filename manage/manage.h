#ifndef __MANAGE_H
#define __MANAGE_H

#include "Lib.h"
#include "certificate.h"
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include "exception.h"

class manage {
private:
    vector<Employee*> v;
public:
    manage() {}
    ~manage() {
        if (!v.empty()) {
            for (Employee* i : v) {
                delete(i);
            }
        }
    }
    void addEmployee();
    void showList(const int&);
    void changeData(const int&);
    void removeEmployee(const string&);
    void findData(const string&);
    void resetSTT();
    bool checkSameID();
    int sizeList() {
        return v.size();
    }
    void addCertificater(const string&);
    void showCertifi(const string&);
};

#endif // !__MANAGE_H
