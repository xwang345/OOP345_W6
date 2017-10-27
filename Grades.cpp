//
// Created by Xiaochen Wang on 2017-10-27.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Grades.h"
using namespace std;

Grades::Grades(char* file) {
    try {
        ifstream fs(file);
        if (fs.is_open()) {
            int line = 0;
            string s;
            while (getline(fs, s)) {
                line++;
            }
            fs.clear();
            fs.seekg(0);
            count_ = line;
            students_ = new string[count_];
            grades_ = new double[count_];
            for (int i = 0; i < count_; i++) {
                fs >> students_[i];
                fs >> grades_[i];
            }
            fs.close();
        }
        else throw "Failed to open file.";
    } catch (const char* msg) {
        cerr << msg << endl;
        exit(0);
    }
}


