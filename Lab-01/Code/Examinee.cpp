//
//  Examinee.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#include "Examinee.h"

Examinee readExaminee(const string &lineInfo) {
    vector<string> tokens = Tokenizer::split(lineInfo, ",");
    Examinee examinee;

    examinee.id              = tokens[0];
    examinee.math            = (tokens[2].empty() ? 0 : stof(tokens[2]));
    examinee.literature      = (tokens[3].empty() ? 0 : stof(tokens[3]));
    examinee.physic          = (tokens[4].empty() ? 0 : stof(tokens[4]));
    examinee.chemistry       = (tokens[5].empty() ? 0 : stof(tokens[5]));
    examinee.biology         = (tokens[6].empty() ? 0 : stof(tokens[6]));
    examinee.history         = (tokens[7].empty() ? 0 : stof(tokens[7]));
    examinee.geography       = (tokens[8].empty() ? 0 : stof(tokens[8]));
    examinee.civicEducation  = (tokens[9].empty() ? 0 : stof(tokens[9]));
    examinee.foreignLanguage = (tokens[12].empty() ? 0 : stof(tokens[12]));

    examinee.naturalScience  = examinee.physic + examinee.chemistry + examinee.biology;
    examinee.socialScience   = examinee.history + examinee.geography + examinee.civicEducation;

    return examinee;
}

vector<Examinee> readExamineeList(const string &filename) {
    ifstream fin(filename);
    vector<Examinee> examineeList;

    if (fin) {
        string line;

        getline(fin, line);
        while (!fin.eof()) {
            getline(fin, line);

            if (line.empty())
                break;
            
            examineeList.push_back(readExaminee(line));
        }

        fin.close();
    }

    return examineeList;
}

void writeTotal(const vector<Examinee> &examineeList, const string outFilename) {
    ofstream fout(outFilename);

    if (fout) {
        float totalScore = 0;

        for (int i = 0; i < examineeList.size(); i++) {
            totalScore = examineeList[i].math +
                         examineeList[i].literature +
                         examineeList[i].foreignLanguage +
                         examineeList[i].naturalScience +
                         examineeList[i].socialScience;

            fout << examineeList[i].id << " " << totalScore << endl;
        }

        fout.close();
    }
}
