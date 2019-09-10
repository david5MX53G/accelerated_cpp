//
// Created by branch on 8/19/19.
//

#include "Core.h"

using std::istream;
using std::string;
using std::vector;

string Core::name() const { return n; }

double Core::grade() const {
    return ::grade(midterm, final, homework);
}

istream& Core::read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
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

bool compare_Core_ptrs(const Core *cp1, const Core *cp2) {
    return compare(*cp1, *cp2);
}

