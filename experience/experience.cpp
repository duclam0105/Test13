#include "experience.h"

//EXPERIENCE FUNCTION===================================================================
void Experience::setEx(const int& ex) { this->ExInYear = ex; }
void Experience::setSkill(const string& skill) { this->ProSkill = skill; }
int Experience::getEx() { return this->ExInYear; }
string Experience::getSkill() { return this->ProSkill; }
void Experience::insertData() {
    Employee::insertData();
    cout << "Nhap so nam kinh nghiem: "; cin >> this->ExInYear;
    cout << "Nhap ki nang chuyen mon: "; cin >> this->ProSkill;
}
void Experience::showInfo() {
    Employee::showInfo();
    cout << " - Experience year: " << this->ExInYear << " - Pro Skill: " << this->ProSkill << endl;
}
