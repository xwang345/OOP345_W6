#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << argv[0] <<
                  ": incorrect number of arguments\n";
        std::cerr << "Usage: " << argv[0] << " file_name\n";
        return 1;
    }

    Grades grades_(argv[1]);

    // define the lambda expression for letter
    auto letter = [](double grades_)->std::string{
        std::string letterGrade;
        if (grades_ >= 90)
            letterGrade = "A+";
        else if (grades_ >= 80)
            letterGrade = "A";
        else if (grades_ >= 75)
            letterGrade = "B+";
        else if (grades_ >= 70)
            letterGrade = "B";
        else if (grades_ >= 65)
            letterGrade = "C+";
        else if (grades_ >= 60)
            letterGrade = "C";
        else if (grades_ >= 55)
            letterGrade = "D+";
        else if (grades_ >= 50)
            letterGrade = "D";
        else
            letterGrade = "F";
        return letterGrade;
    };

    grades_.displayGrades(std::cout, letter);

    std::cout << "Press any key to continue ... ";
    std::cin.get();
}
