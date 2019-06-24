#include "Student_info.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

// create Student_info from input stream
istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

// code for read_hw(istream, vector<double>& from 57
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // clear contents of var
        hw.clear();

        // read istream into vector<double>
        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        // reset any error conditions
        in.clear();
    }
    return in;
}
