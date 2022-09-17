#include "intern.h"

//INTERN FUNCTION=====================================================================//
void Intern::setMajors(const string& majors) { this->Majors = majors; }
void Intern::setSemester(const int& semester) { this->Semester = semester; }
void Intern::setUniversity(const string& univer) { this->University = univer; }
string Intern::getMajors() { return this->Majors; }
int Intern::getSemester() { return this->Semester; }
string Intern::getUniversity() { return this->University; }
void Intern::insertData() {
    Employee::insertData();
    cout << "Nhap chuyen nganh: "; cin >> this->Majors;
    cout << "Nhap ki hoc: "; cin >> this->Semester;
    cout << "Nhap truong dai hoc: "; cin >> this->University;
}
void Intern::showInfo() {
    Employee::showInfo();
    cout << " - Majors: " << this->Majors << " - Semester: " << this->Semester << " - University: " << this->University << endl;
}

