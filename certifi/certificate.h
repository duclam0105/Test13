#ifndef __CERTIFICATE_H
#define __CERTIFICATE_H

#include "Lib.h"

class Certificate {
    string CertificateID;
    string CertificateName;
    string CertificateRank;
    string CertificateDate;
public:
    void setCertificateID(const string&);
    void setCertificateName(const string&);
    void setCertificateRank(const string&);
    void setCertificateDate(const string&);
    string getCertificateID();
    string getCertificateName();
    string getCertificateRank();
    string getCertificateDate();
    void showCertifi();
    void insertCertifi();
};

#endif // !__CERTIFICATE_H
