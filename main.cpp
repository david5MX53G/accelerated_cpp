#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"

#include <Picture.cpp>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

int main() {
    vector<Student_info> students;
    Student_info s;

    while (s.read(cin))
        students.push_back(s);
    cout << "students: " << students.size() << endl;

    sort(students.begin(), students.end(), Student_info::compare);
    cout << "First student: " << students[0].name() << std::endl;

    //cout << frame(histogram(students)) << endl;
    return 0;
}

#pragma clang diagnostic pop