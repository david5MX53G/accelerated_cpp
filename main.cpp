#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"

#include <Picture.h>
#include <Student_info.cpp>
#include <iostream>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::ifstream;

int main() {
    vector<Student_info> students;
    Student_info s;

    ifstream ifs;
    ifs.open("../students.txt", std::ifstream::out);

    if (ifs.is_open()) {
        while (s.read(ifs)) {
            students.push_back(s);
        }
        ifs.close();
    }

    sort(students.begin(), students.end(), Student_info::compare);

    cout << frame(histogram(students)) << endl;
    return 0;
}

#pragma clang diagnostic pop