//
// Created by Xiaochen Wang on 2017-10-27.
//

#ifndef SICT_GRADES_H_
#define SICT_GRADES_H_

// Grades.h
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Grades
{
    string* students_;
    double* grades_;
    int count_;

public:
    Grades()
            : students_(nullptr), grades_(nullptr), count_(0) {}

    Grades(char* file);

    template<typename T>
    void displayGrades(std::ostream& os, T t) const {
        for (int i = 0; i < count_; i++)
            os << students_[i] << " " << grades_[i] << "0" << " " << t(grades_[i]) << endl;
    };

    Grades(const Grades& g) = delete;
    Grades(Grades&& g) = delete;
    Grades& operator=(const Grades& g) = delete;
    Grades&& operator=(Grades&& g) = delete;
};

#endif // SICT_GRADES_H
