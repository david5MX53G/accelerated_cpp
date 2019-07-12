#ifndef ACCELERATED_CPP_STUDENT_INFO_H
#define ACCELERATED_CPP_STUDENT_INFO_H
#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read(std::istream&);
    double grade() const;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif
