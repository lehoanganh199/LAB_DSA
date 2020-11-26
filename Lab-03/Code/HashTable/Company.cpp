#include "Company.h"
#include "Tokenizer.h"

bool readCompanyInfo(ifstream &fin, Company &company) {
	string data;
	getline(fin, data);

	if (data.empty() || data == "\n")
		return false;

	vector<string> tokens = Tokenizer::split(data, "|");
	if (tokens.size() != 3)
		return false;

	company.name 		= tokens[0];
	company.profit_tax 	= tokens[1];
	company.address 	= tokens[2];

	return true;
}

vector<Company> ReadCompanyList(const string &file_name) {
	ifstream fin(file_name);
	vector<Company> companyList;

	if (fin) {
		string ignoreLine;
		getline(fin, ignoreLine);

		while (!fin.eof()) {
			Company company;
			
			if (readCompanyInfo(fin, company))
				companyList.push_back(company);
		}

		fin.close();
	}

    return companyList;
}

long long HashString(const string &company_name) {
    int p = 31;
    int m = 1000000009;

    size_t len = company_name.length();
    size_t startIndex = (len > 20) ? (len - 20) : 0;

    unsigned long long hashValue = 0;
    unsigned long long pPower = 1;

    // (a + b) % c = ((a % c) + (b % c)) % c.
    // (a * b) % c = ((a % c) * (b % c)) % c.
    while (startIndex < len) {
        hashValue = ((hashValue % m) + (((int)company_name[startIndex] * pPower) % m)) % m;
        pPower = (pPower * p) % m;
        ++startIndex;
    }

    return hashValue;
}

Company* CreateHashTable(const vector<Company> &list_company) {
	Company* hashTable = new Company[2000];

	if (hashTable) {
		for (const Company &company : list_company)
			Insert(hashTable, company);
	}

	return hashTable;
}

void Insert(Company* &hash_table, const Company &company) {
	if (hash_table) {
		long long hashValue = HashString(company.name);
		int index = hashValue % SIZE;

		hash_table[index].name       = company.name;
		hash_table[index].profit_tax = company.profit_tax;
		hash_table[index].address    = company.address;
	}
}

Company* Search(Company* &hash_table, const string &company_name) {
	Company* company = nullptr;

	if (hash_table) {
		long long hashValue = HashString(company_name);
		int index = hashValue % SIZE;

		if (hash_table[index].name == company_name) {
			company = new Company;
			
			company->name 		= hash_table[index].name;
			company->profit_tax = hash_table[index].profit_tax;
			company->address 	= hash_table[index].address;
		}
	}

	return company;
}





