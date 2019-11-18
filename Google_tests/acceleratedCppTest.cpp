#include "lib/googletest/include/gtest/gtest.h"
#include <fstream>
#include "Core.cpp"
#include "Grad.cpp"
#include "grade.cpp"
#include "median.cpp"
#include "Student_info.cpp"
#include <filesystem>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::endl;

namespace fs = std::__fs::filesystem;

TEST(acceleratedCppTestSuite, mainTest){
    vector<Student_info> students;
    Student_info s;

    // read in ../students.txt
    ifstream ifs;
    ifs.open("../../students.txt", std::ifstream::out);

    EXPECT_TRUE(ifs.is_open()) << "failed to open students.txt using current path: " + fs::current_path().string();

    if (ifs.is_open()) {
        while (s.read(ifs)) {
            students.push_back(s);
        }
        ifs.close();
    }

    EXPECT_GT(students.size(),0) << "failed to instantiate students vector";

    /*sort(students.begin(), students.end(), Student_info::compare);

    ofstream ofs("../students_out.txt");
    ofs.close();*/
}