//
// Created by branch on 7/13/19.
//
#include <vector>
#include <stdexcept>
#include "median.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
   if (hw.empty())
       throw domain_error("student has done no homework!");

   return grade(midterm, final, median(hw));
}