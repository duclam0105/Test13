#include "Lib.h"
#include "Lib.h"
#include "certificate.h"
#include "employee.h"
#include "exception.h"
#include "fresher.h"
#include "intern.h"
#include "manage.h"

int Employee::Employee_count = 0;

//====MAIN========//   
int main() {
    int temp;
    manage m;
    string tmp;
    int a;
    while (true)
    {
        cout << "==================================================\n";
        cout << "1-Them moi nhan vien\n2-Xoa nhan vien\n3-Tim kiem\n4-Hien thi danh sach\n5-Them chung chi\n6-Hien thi chung chi"
            << "\n0-Thoat\nMoi ban nhap: ";
        cin >> temp;
        cout << "========\n";
        switch (temp) {
        case cmd_exit: {
            cout << "Close the program..." << endl;
            system("cls");
            return 0;
        }
        case cmd_add:
            m.addEmployee();
            break;
        case cmd_remove: {
            cout << "Nhap ID cua nhan vien can xoa: "; cin >> tmp;
            m.removeEmployee(tmp);
            tmp = "";
            break;
        }
        case cmd_find: {
            cout << "Nhap ID cua nhan vien can tim kiem: "; cin >> tmp;
            m.findData(tmp);
            tmp = "";
            break;
        }
        case cmd_showlist: {
            cout << "0-All; 1-Experience; 2-Fresher; 3-Intern: ";
            cin >> a;
            cout << "==============\n";
            m.showList(a);
            break;
        }
        case cmd_addCertifi: {
            string id;
            cout << "Nhap ID cua nhan su: ";
            cin >> id;
            m.addCertificater(id);
            break;
        }
        case cmd_showCertifi: {
            string id1;
            cout << "Nhap ID cua nhan su: ";
            cin >> id1;
            m.showCertifi(id1);
            break;
        }
        default:
            break;
        }
    }
    cout << "Close the program..." << endl;
    return 0;
}
