#ifndef COMPANY_H_
#define COMPANY_H_

#include <vector>
#include <string>
#include <fstream>

#define FILE_NAME 	"/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Lab-03/Code/HashTable/MST.txt"
#define SIZE 		2000

using namespace std;

struct Company {
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(const string &file_name);

long long HashString(const string &company_name);

Company* CreateHashTable(const vector<Company> &list_company);

void Insert(Company* &hash_table, const Company &company);

Company* Search(Company* &hash_table, const string &company_name);

#endif
