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
	company.profitTax 	= tokens[1];
	company.address 	= tokens[2];

	return true;
}

vector<Company> ReadCompanyList(const string &filename) {
	ifstream fin(filename);
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

long long HashString(const string &companyName) {
    int p = 31;
    int m = 1000000009;

    size_t len = companyName.length();
    size_t startIndex = (len > 20) ? (len - 20) : 0;

    long long hashValue = 0;
    long long pPower = 1;

    // (a + b) % c = ((a % c) + (b % c)) % c.
    // (a * b) % c = ((a % c) * (b % c)) % c.
    while (startIndex < len) {
        hashValue = ((hashValue % m) + (((int)companyName[startIndex] * pPower) % m)) % m;
        pPower = (pPower * p) % m;
        ++startIndex;
    }

    return hashValue;
}

Company* CreateHashTable(const vector<Company> &companyList) {
	Company* hashTable = new Company[SIZE_HASH_TABLE];

	if (hashTable)
		for (const Company &company : companyList)
			Insert(hashTable, company);

	return hashTable;
}

void Insert(Company* &hashTable, const Company &company) {
	if (hashTable) {
		long long hashValue = HashString(company.name);
		int index = hashValue % SIZE_HASH_TABLE;
		hashTable[index] = company;
	}
}

Company* Search(Company* &hashTable, const string &companyName) {
	Company* company = nullptr;

	if (hashTable) {
		long long hashValue = HashString(companyName);
		int index = hashValue % SIZE_HASH_TABLE;

		if (hashTable[index].name == companyName) {
			company = new Company;

            if (company)
                *company = hashTable[index];
		}
	}

	return company;
}
