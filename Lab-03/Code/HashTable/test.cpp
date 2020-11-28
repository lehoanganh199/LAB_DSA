#include <iostream>
#include "Company.h"

void printInfoCompany(const Company &company) {
    cout << "- NAME       : " << company.name << endl;
    cout << "- PROFIT TAX : " << company.profitTax << endl;
    cout << "- ADDRESS    : " << company.address << endl;
}

int main() {
    vector<Company> companyList = ReadCompanyList(FILE_NAME);
    Company* hashTable = CreateHashTable(companyList);

    if (hashTable) {
        // INSERT.
        // -----------------------------------------------------------
        Company company1;
        company1.name        = "CONG TY TNHH GIAO DUC BAO MINH CHAU";
        company1.profitTax   = "9641763063";
        company1.address     = "227 NVC, Q5, TPHCM";
        Insert(hashTable, company1);

        Company company2;
        company2.name       = "LE HOANG ANH";
        company2.profitTax  = "0386192902";
        company2.address    = "Khong Biet";
        Insert(hashTable, company2);
        // -----------------------------------------------------------


        // SEARCH.
        // -----------------------------------------------------------
        Company* company3 = Search(hashTable, "CONG TY TNHH QUANG CAO THUONG MAI DICH VU XAY DUNG SANG TAO TUONG LAI");
        if (company3) {
            printInfoCompany(*company3);
            delete company3;
        }
        else
            cout << "==> \"CONG TY TNHH QUANG CAO THUONG MAI DICH VU XAY DUNG SANG TAO TUONG LAI\" was not found." << endl;


        cout << endl;


        company3 = Search(hashTable, "CONG TY TNHH GIAO DUC BAO MINH CHAU");
        if (company3) {
            printInfoCompany(*company3);
            delete company3;
        }
        else
            cout << "==> \"CONG TY TNHH GIAO DUC BAO MINH CHAU\" was not found." << endl;


        cout << endl;


        company3 = Search(hashTable, "LE HOANG ANH");
        if (company3) {
            printInfoCompany(*company3);
            delete company3;
        }
        else
            cout << "==> \"LE HOANG ANH\" was not found." << endl;


        cout << endl;


        company3 = Search(hashTable, "CONG TY DA CAP");
        if (company3) {
            printInfoCompany(*company3);
            delete company3;
        }
        else
            cout << "==> \"CONG TY DA CAP\" was not found." << endl;
        // -----------------------------------------------------------

        delete[] hashTable;
    }

    return 0;
}
