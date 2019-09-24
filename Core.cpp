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

istream& Core::read(istream& in) {
    read_common(in);
    read_hw(in, homework);
    return in;
};

bool compare_Core_Handles(const Handle<Core> &hc1, const Handle<Core> &hc2) {
    return hc1->name() < hc2->name();
}
