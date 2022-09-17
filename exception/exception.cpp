#include "exception.h"

bool checkName(string name) {     //khong duoc chua chu so (tu 48 den 57 trong bang ma ascii)
    try {
        stringstream ss(name);
        string token;
        while (ss >> token)
        {
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] > 47) && (token[i] < 58)) {
                    throw nameException("Invalid name!");
                }
            }
        }
    }
    catch (nameException& ex1) {
        cout << ex1.what() << endl;
        return false;
    }
    return true;
}
bool checkDate(string date) {
    try {                                    //birthday form: dd/mm/yy
        stringstream ss(date);              //               01234567
        string token;                       //  dd: 1->31; mm: 1->12; yy: thoai mai;
        while (ss >> token)
        {
            if (token.length() != 8) {
                throw dateException("Invalid date! - dd/mm/yy");
            }
            if ((token[2] != '/') || (token[5] != '/')) {
                throw dateException("Invalid date! - dd/mm/yy");
            }
            for (int i = 0; i < token.length(); i++) {
                //Khong duoc co chu cai
                if ((i != 2) && (i != 5)) {
                    if ((token[i] < 48) || (token[i] > 57)) {
                        throw dateException("Invalid date! - dd/mm/yy");
                    }
                }
            }
        }
        stringstream ss1;
        int day, month, year;// = stoi(sday);
        ss1 << date.substr(0, 2);
        ss1 >> day; ss1.clear();
        ss1 << date.substr(3, 2);
        ss1 >> month; ss1.clear();
        ss1 << date.substr(6, 2);
        ss1 >> year; ss1.clear();
        if ((day < 1) || (day > 31) || (month < 1) || (month > 12)) {
            throw dateException("Ngay khong hop le! (4) Sai form: dd/mm/yy");
        }
    }
    catch (dateException& ex2) {
        cout << ex2.what() << endl;
        return false;
    }
    return true;
    // cout <<day<< "/"<<month<<"/"<<year;
}
bool checkPhone(string phone) {
    try {
        stringstream ss(phone);
        string token;
        while (ss >> token)
        {
            if (token.length() != 10) {
                throw phoneException("Invalid phone number!");
            }
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] < 48) || (token[i] > 57)) {
                    throw phoneException("Invalid phone number!");
                }
            }
        }
    }
    catch (phoneException& ex3) {
        cout << ex3.what() << endl;
        return false;
    }
    return true;
}
bool checkMail(string mail, string mail_template) {
    try {
        stringstream ss(mail);                          // vidu: template: @gmail.com  
        string token;                                   // mail phai co dang: ... + @gmail.com                 
        string temp = "";                               // (10 chu cuoi phai la "@gmail.com")
        if (mail_template.length() == 0) {
            return false;
        }
        while (ss >> token)
        {
            if (token.length() < mail_template.length() + 1) {
                throw emailException("Invalid email! Mail form: \"...\" + " + mail_template);
            }
            for (int i = token.length() - mail_template.length(); i < token.length(); i++) {
                temp += token[i];
            }
        }
        if (temp != mail_template) {
            throw emailException("Invalid email! Mail form: \"...\" + " + mail_template);
        }
    }
    catch (emailException& ex4) {
        cout << ex4.what() << endl;
        return false;
    }
    return true;
    // cout << temp;
}
