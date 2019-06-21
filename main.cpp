#include <iostream>
#include <string>
#include <algorithm>
#include <ios>
#include <vector>
#include <iomanip>

using std::cin;         using std::endl;
using std::cout;        using std::string;
using std::setprecision;using std::sort;
using std::streamsize;  using std::vector;

int main() {
    // greeting
    cout << "What's your name? ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // get grades
    cout << "Enter midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    cout << "Midterm: " << midterm << endl;
    cout << "Final: " << final << endl;
    cout << "Enter all your homework grades, ended by -1: ";
    vector<double> homework;
    double x;

    // invariant: homework contains all homework grades read so far
    typedef vector<double>::size_type vec_sz;
    vec_sz size = 0;
    while (cin >> x && x != -1) {
        homework.push_back(x);
        size = homework.size();
    }

    // check input
    if (size == 0) {
        cout << endl << "ENTER YOUR GRADES!";
        return 1;
    }

    // compute grades
    else {
        sort(homework.begin(), homework.end());
        vec_sz mid = size/2;
        cout << endl << "Grades: " << size;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
        cout << endl << "Median: " << median;
        streamsize prec = cout.precision();
        cout << endl << "Your final grade: " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median
             << setprecision(prec);
        return 0;
    }
}
