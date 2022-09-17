#include "employee.h"

//EMPLOYEE FUNCTION===================================================================
void Employee::setID(const string& id) { this->ID = id; }
void Employee::setName(const string& name) { this->name = name; }
void Employee::setBirthday(const string& birthday) { this->birthday = birthday; }
void Employee::setPhone(const string& phone) { this->phone = phone; }
void Employee::setEmail(const string& email) { this->email = email; }
void Employee::setType(const Employee_type& et) { this->et = et; }
string Employee::getID() { return this->ID; }
string Employee::getName() { return this->name; }
string Employee::getBirthday() { return this->birthday; }
string Employee::getPhone() { return this->phone; }
string Employee::getEmail() { return this->email; }
Employee_type Employee::getType() { return this->et; }
//void Employee::chuanhoaTen() {
//    string res = "";
//    stringstream ss(this->getName());
//    string token;
//    while (ss >> token)
//    {
//        res += toupper(token[0]);
//        for (int i = 1; i < token.length(); i++) {
//            res += tolower(token[i]);
//        }
//        res += " ";
//    }
//    res.erase(res.length() - 1);
//    this->setName(res);
//}
void Employee::insertData() {
    string tmp_name, tmp_date, tmp_phone, tmp_mail;
    cout << "Nhap ID: "; cin >> this->ID;
    cin.ignore();
    do {
        cout << "Nhap ten: "; 
        getline(cin, tmp_name);
        chuanhoaTen(tmp_name);
        if (tmp_name == "0") break;
    } while (!checkName(tmp_name));
    this->name = tmp_name;
    do {
        cout << "Nhap ngay sinh: ";
        cin >> tmp_date;
        if (tmp_name == "0") break;
    } while (!checkDate(tmp_date));
    this->birthday = tmp_date;
    do {
        cout << "Nhap sdt: "; 
        cin >> tmp_phone;
        if (tmp_name == "0") break;
    } while (!checkPhone(tmp_phone));
    this->phone = tmp_phone;
    do {
        cout << "Nhap email: "; 
        cin >> tmp_mail;
        if (tmp_name == "0") break;
    } while (!checkMail(tmp_mail));
    this->email = tmp_mail;
}
void Employee::showInfo() {
    cout << "ID: " << this->ID << " - Name: " << this->name << " - Birthday: " << this->birthday << " - Phone: " <<
        this->phone << " - Email: " << this->email;
}
void Employee::pushCertifi(Certificate* pc) {
    vc.push_back(pc);
}
void Employee::eraseCertifi(const int& index) {
    vc.erase(vc.begin() + index);
}
void Employee::showListCertifi() {
    if (vc.empty()) {
        cout << "Khong co du lieu!" << endl;
        return;
    }
    for (int i = 0; i < vc.size(); i++) {
        cout << i + 1 << ". ";
        vc[i]->showCertifi();
    }
}

