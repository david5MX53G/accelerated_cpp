#include "lib/googletest/include/gtest/gtest.h"
#include <fstream>
#include "Core.cpp"
#include "Grad.cpp"
#include "grade.cpp"
#include "median.cpp"
#include "Student_info.cpp"

using std::vector;
using std::ifstream;
using std::ofstream;
using std::istream;

TEST(acceleratedCppTestSuite, mainTest){
    vector<Student_info> students;
    Student_info s;

    // read in ../students.txt
    ifstream ifs("../students.txt");

    while (s.read(ifs))
        students.push_back(s);

    ifs.close();

    sort(students.begin(), students.end(), Student_info::compare);

    ofstream ofs("../students_out.txt");
    ofs.close();

    EXPECT_GT(students.size(),0);
}