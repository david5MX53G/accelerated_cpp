//
// Created by branch on 8/19/19.
//

#include <string>
#include "Core.h"

using std::istream;
using std::string;

string Core::name() const { return n; }

double Core::grade() const {
    return Core::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in) {
    in >> n >> midterm >> final;
    return in;
}

bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2) {
    return c1.grade() < c2.grade();
}