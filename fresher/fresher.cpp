#include "fresher.h"

//FRESHER FUNCTION=====================================================================
void Fresher::setGraduationDate(const string& gdate) { this->Graduation_date = gdate; }
void Fresher::setGraduationRank(const string& grank) { this->Graduation_rank = grank; }
void Fresher::setEducation(const string& edu) { this->Education = edu; }
string Fresher::getGraduationDate() { return this->Graduation_date; }
string Fresher::getGraduationRank() { return this->Graduation_rank; }
string Fresher::getEducation() { return this->Education; }
void Fresher::insertData() {
    Employee::insertData();
    cout << "Nhap ngay tot nghiep: ";   cin >> this->Graduation_date;
    cout << "Nhap loai tot nghiep: ";   cin >> this->Graduation_rank;
    cout << "Nhap truong dai hoc: ";    cin >> this->Education;
}
void Fresher::showInfo() {
    Employee::showInfo();
    cout << " - Graduation date: " << this->Graduation_date << " - Graduation rank: " <<
        this->Graduation_rank << " - Education: " << this->Education << endl;
}
