#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

// code for grade(double, double, double) from 52
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// code for grade(double, double, const vector<double>) from 54
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

// calculate grade for Student_info struct
double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

