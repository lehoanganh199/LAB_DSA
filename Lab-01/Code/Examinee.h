//
//  Examinee.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#ifndef EXAMINEE_H_
#define EXAMINEE_H_

#include "Tokenizer.h"
#include <fstream>

#define INPUT_FILE_NAME     "/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Lab-01/Code/data.txt"
#define OUTPUT_FILE_NAME    "/Users/lehoanganh/Desktop/HoangAnh/SecondYear/HK1/DSA/LAB/Lab-01/Code/output.txt"

using namespace std;

struct Examinee {
    string id;
    float math;
    float literature;
    float physic;
    float chemistry;
    float biology;
    float history;
    float geography;
    float civicEducation;
    float naturalScience;   // physic + chemistry + biology.
    float socialScience;    // history + geography + civicEducation.
    float foreignLanguage;  // math + literature + foreignLanguage + naturalScience + socialScience.
};

Examinee readExaminee(const string &lineInfo);

vector<Examinee> readExamineeList(const string &filename);

void writeTotal(const vector<Examinee> &examineeList, const string outFilename);

#endif
