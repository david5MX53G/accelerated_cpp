#include "Student_info.h"
#include "grade.h"

using std::istream; using std::vector;

// between the : and { are "constructor initializers"; these set default values of the given members
Student_info::Student_info(): midterm(0), final(0) {}

// midterm and final are populated by "read(is)"
Student_info::Student_info(istream& is): midterm(0), final(0) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
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

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

// const member functions have "const" on the end of their def; these functions aren't allowed to modify the internal
// state of the parent object
double Student_info::grade() const {
    // double colon forces a call to the version of "grade" that is not in the implicit namespace Student_info::
    return ::grade(midterm, final, homework);
}