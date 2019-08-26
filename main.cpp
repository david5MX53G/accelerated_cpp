#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
#include "Grad.h"
#include <algorithm>
#include <iomanip>

using std::streamsize;
using std::endl;
using std::string;
using std::max;
using std::cin;
using std::vector;
using std::sort;
using std::cout;
using std::setprecision;
using std::domain_error;

int main() {
    vector<Core> students;
    Core record;
    string::size_type maxlen = 0;

    // read data into students vector
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // alphabetize student vector
    sort(students.begin(), students.end(), compare);

    // write names and grades
    for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}

#pragma clang diagnostic pop