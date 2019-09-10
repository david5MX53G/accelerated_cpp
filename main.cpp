#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
#include "Handle.h"
#include "Core.h"
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
    vector< Handle<Core> > students;
    Handle<Core> record;
    char ch;
    string::size_type maxlen = 0;

    // read data into students vector
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    // alphabetize student vector using pointer-friendly compare function
    sort(students.begin(), students.end(), compare_Core_Handles);

    // write names and grades
    for (vector< Handle<Core> >::size_type i = 0; i != students.size(); ++i) {
        // write name
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(), ' ');

        // write grade
        try {
            double final_grade = students[i]->grade();
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