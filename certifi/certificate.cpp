#include "certificate.h"

//CERTIFICATE FUNCTION================================================================//
void Certificate::setCertificateID(const string& id) { this->CertificateID = id; }
void Certificate::setCertificateName(const string& name) { this->CertificateName = name; }
void Certificate::setCertificateRank(const string& rank) { this->CertificateRank = rank; }
void Certificate::setCertificateDate(const string& date) { this->CertificateDate = date; }
string Certificate::getCertificateID() { return this->CertificateID; }
string Certificate::getCertificateName() { return this->CertificateName; }
string Certificate::getCertificateRank() { return this->CertificateRank; }
string Certificate::getCertificateDate() { return this->CertificateDate; }
void Certificate::showCertifi() {
    cout << "CERTIFICATE ID: " << this->CertificateID << " - Name: " << this->CertificateName << " - Rank: "
        << this->CertificateRank << " - Date: " << this->CertificateDate << endl;
}
void Certificate::insertCertifi() {
    cout << "CERTIFICATE ID: ";     cin >> this->CertificateID;
    cout << "Name: ";               cin >> this->CertificateName;
    cout << "Rank: ";                cin >> this->CertificateRank;
    cout << "Date: ";               cin >> this->CertificateDate;
}
