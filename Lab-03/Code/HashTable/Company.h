#ifndef COMPANY_H_
#define COMPANY_H_

#include <vector>
#include <string>
#include <fstream>

#define FILE_NAME 			"/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Lab-03/Code/HashTable/MST.txt"
// #define FILE_NAME 			"MST.txt"
#define SIZE_HASH_TABLE 	2000

using namespace std;

struct Company {
	string name;
	string profitTax;
	string address;
};

vector<Company> ReadCompanyList(const string &filename);

long long HashString(const string &companyName);

Company* CreateHashTable(const vector<Company> &companyList);

void Insert(Company* &hashTable, const Company &company);

Company* Search(Company* &hashTable, const string &companyName);

#endif
