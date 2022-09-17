#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Lib.h"
#include "certificate.h"
#include "exception.h"

class Employee {
    friend class Certificate;
private:
    string ID;
    string name;
    string birthday;        //form: dd/mm/yy
    string phone;
    string email;
    Employee_type et;           //0: Experience, 1: Fresher , 2: Intern 
    vector <Certificate*> vc;
public:
    static int Employee_count;
    Employee() {}
    virtual ~Employee() {}
    int STT;
    /*friend void chuanhoaTen(Employee&);*/
    virtual void insertData();
    virtual void showInfo();
    void setID(const string&);
    void setName(const string&);
    void setBirthday(const string&);
    void setPhone(const string&);
    void setEmail(const string&);
    void setType(const Employee_type&);
    string getID();
    string getName();
    string getBirthday();
    string getPhone();
    string getEmail();
    Employee_type getType();
    /*void chuanhoaTen();*/
    void pushCertifi(Certificate*);
    void eraseCertifi(const int&);
    void showListCertifi();
};

#endif // !__EMPLOYEE_H
