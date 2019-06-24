#include <iostream>
#include <string>
#include <algorithm>
#include <ios>
#include <vector>
#include <iomanip>
#include "grade.h"
#include "Student_info.h"

using std::cin;          using std::setprecision;
using std::cout;         using std::sort;
using std::domain_error; using std::streamsize;
using std::endl;         using std::string;
using std::max;          using std::vector;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store student data
    // invariant: students contains all records read so far
    //            maxlen contains length of longest student name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // order records
    sort(students.begin(), students.end(), compare);

    // write name and grade of each
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
