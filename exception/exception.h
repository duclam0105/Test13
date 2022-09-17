#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include "Lib.h"

class nameException {
    string msg;
public:
    nameException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class dateException {
    string msg;
public:
    dateException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class phoneException {
    string msg;
public:
    phoneException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class emailException {
    string msg;
public:
    emailException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class myException {
    string msg;
public:
    myException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
#endif // !__EXCEPTION_H
