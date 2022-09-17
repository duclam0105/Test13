#include "Lib.h"

void chuanhoaTen(string &name) {
    string res = "";
    stringstream ss(name);
    string token;
    while (ss >> token)
    {
        res += toupper(token[0]);
        for (int i = 1; i < token.length(); i++) {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    name = res;
}