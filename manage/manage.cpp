#include "manage.h"

//MANAGEMENT FUCNTION==================================================================//
void manage::addEmployee() {
    int a;
    cout << "1-Experience - 2-Fresher - 3-Intern: ";
    cin >> a;
    switch (a) {
    case exit_t:
        return;
    case experience_t: {
        Experience* p = new Experience;
        p->insertData();
        p->setType(experience);
        v.push_back(p);
        p->Employee_count++;
        // p->STT = p->Employee_count;
        break;
    }
    case fresher_t: {
        Fresher* p = new Fresher;
        p->insertData();
        p->setType(fresher);
        v.push_back(p);
        p->Employee_count++;
        //p->STT = p->Employee_count;
        break;
    }
    case intern_t: {
        Intern* p = new Intern;
        p->insertData();
        p->setType(intern);
        v.push_back(p);
        p->Employee_count++;
        //p->STT = p->Employee_count;
        break;
    }
    default:
        cout << "Nhap sai! Nhap so trong khoang 0 - 3\n";
        break;
    }
    if (manage::checkSameID()) {
        Employee* tmp = v[v.size() - 1];
        v.pop_back();
        delete(tmp);
        /*manage::addEmployee();*/
    }
    //// CHECK EXCEPTION
    //if (!checkName(v[v.size() - 1]->getName())) {
    //    v.pop_back();
    //    manage::addEmployee();
    //}
    //if (!checkDate(v[v.size() - 1]->getBirthday())) {
    //    v.pop_back();
    //    manage::addEmployee();
    //}
    //if (!checkPhone(v[v.size() - 1]->getPhone())) {
    //    v.pop_back();
    //    manage::addEmployee();
    //}
    //if (!checkMail(v[v.size() - 1]->getEmail(), "@gmail.com")) {
    //    v.pop_back();
    //    manage::addEmployee();
    //}
    int q;
    cout << "Ban co muon nhap tiep? 1-Yes/0-No: "; cin >> q;
    if (q == yes) {
        manage::addEmployee();
    }
}
void manage::resetSTT() {
    if (v.empty()) { return; }
    for (int i = 0; i < v.size(); i++) {
        v[i]->STT = i;
    }
}
void manage::removeEmployee(const string& id) {
    if (v.empty()) {
        cout << "Chua co du lieu!" << endl;
        return;
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            Employee* tmp = v[i];
            v.erase(v.begin() + i);
            delete(tmp);
            count++;
            i--;
        }
    }
    if (count == 0) {
        cout << "Khong co nguoi nao co ID:" << id << endl;
        return;
    }
    cout << "Da xoa thanh cong" << endl;
}
void manage::findData(const string& id) {
    if (v.empty()) {
        cout << "Chua co du lieu!" << endl;
        return;
    }
    int tmp = 0;
    uint8_t count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            // v1.push_back(v[i]);
            tmp = i;                //Moi employee co mot ID rieng khong trung nhau
            count++;
        }
    }
    if (count != 0) {
        v[tmp]->showInfo();
        cout << "Nhap 1-Sua du lieu/ 0-Thoat: ";
        int a = 0; cin >> a;
        if (a == 1) {
            manage::changeData(tmp);
        }
        else if (a == 0) {
            return;
        }
    }
    else if (tmp == 0) {
        cout << "Khong co nhan su nao co ID " << id << endl;
    }
}
bool manage::checkSameID() {
    try {
        if (v.size() > 1) {
            for (int i = 0; i < v.size() - 1; i++) {
                if (v[i]->getID() == v[v.size() - 1]->getID()) {      //Khong co nguoi nao co ID trung nhau
                    //v.pop_back();
                    throw myException("ID bi trung. Hay nhap lai");
                }
            }
        }
    }
    catch (myException &e) {
        cout << e.what() << endl;
        return true;
    }
    return false;
}
void manage::changeData(const int& index) {
    v[index]->insertData();
    if (manage::checkSameID()) {
        v[index]->insertData();
    }
}
void manage::showList(const int& typeshow) {
    if (v.size() == 0) {
        cout << "Khong co phan tu nao trong danh sach!" << endl;
        return;
    }
    if (typeshow == 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << i + 1 << ": ";
            if (v[i]->getType() == experience) {
                Experience* p = dynamic_cast<Experience*>(v[i]);
                if (p == nullptr) { cout << "Haha ex!"; }
                p->showInfo();
            }
            if (v[i]->getType() == fresher) {
                Fresher* p = dynamic_cast<Fresher*>(v[i]);
                if (p == nullptr) { cout << "Haha fr!"; }
                p->showInfo();
            }
            if (v[i]->getType() == intern) {
                Intern* p = dynamic_cast<Intern*>(v[i]);
                if (p == nullptr) { cout << "Haha in!"; }
                p->showInfo();
            }
        }
    }
    else if (typeshow == experience_t) {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getType() == experience) {
                count++;
                cout << i + 1 << ": ";
                Experience* p = dynamic_cast<Experience*>(v[i]);
                if (p == nullptr) { cout << "Haha ex!"; }
                p->showInfo();
            }
        }
        if (count == 0) { cout << "Khong co nhan su Experience trong danh sach!" << endl; }
    }
    else if (typeshow == fresher_t) {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getType() == fresher) {
                count++;
                cout << i + 1 << ": ";
                Fresher* p = dynamic_cast<Fresher*>(v[i]);
                if (p == nullptr) { cout << "Haha fr!"; }
                p->showInfo();
            }
        }
        if (count == 0) { cout << "Khong co nhan su Fresher trong danh sach!" << endl; }
    }
    else if (typeshow == intern_t) {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getType() == intern) {
                count++;
                cout << i + 1 << ": ";
                Intern* p = dynamic_cast<Intern*>(v[i]);
                if (p == nullptr) { cout << "Haha in!"; }
                p->showInfo();
            }
        }
        if (count == 0) { cout << "Khong co nhan su Intern trong danh sach!" << endl; }
    }
}
void manage::addCertificater(const string& id) {
    int index;
    uint8_t k = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            index = i;
            k++;
        }
    }
    if (k == 0) {
        cout << "Khong co nhan su nao co ID " << id << endl;
        return;
    }
    Certificate* pc = new Certificate;
    pc->insertCertifi();
    v[index]->pushCertifi(pc);
    int q;
    cout << "Ban co muon nhap them? 1-Yes/0-No: "; cin >> q;
    if (q == yes) {
        manage::addCertificater(id);
    }
}
void manage::showCertifi(const string& id) {
    int index;
    uint8_t k = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id) {
            index = i;
            k++;
        }
    }
    if (k == 0) {
        cout << "Khong co nhan su nao co ID " << id << endl;
        return;
    }
    v[index]->showListCertifi();
}
