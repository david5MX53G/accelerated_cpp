#include "lib/googletest/include/gtest/gtest.h"
#include <fstream>
#include "Core.cpp"
#include "Grad.cpp"
#include "grade.cpp"
#include "median.cpp"
#include "Student_info.cpp"
#include <filesystem>
#include <iostream>
#include "Ptr.cpp"
#include "Ptr.h"

using std::vector;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::endl;
using std::string;

namespace fs = std::__fs::filesystem;

TEST(acceleratedCppTestSuite, ptrTest) {
    Ptr<string> ptr(new string("hello!"));
    EXPECT_EQ(*ptr, "hello!");
}

TEST(acceleratedCppTestSuite, pictureTest){
    vector<string> strv;
    ifstream ifs;
    ifs.open("../../students.txt", std::ifstream::out);

    EXPECT_TRUE(ifs.is_open()) << "failed to open students.txt from path: " + fs::current_path().string();

    string x;

    while(ifs >> x) {
        strv.push_back(x);
        std::cout << x << endl;
    }

    ifs.close();
}

TEST(acceleratedCppTestSuite, studentTest){
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

    std::cout << endl << "before sort..." << endl;

    for (std::vector<Student_info>::iterator i = students.begin(); i != students.end(); ++i) {
        std::cout << i->name() << ": " << i->grade() << endl;
    }

    sort(students.begin(), students.end(), Student_info::compare);

    std::cout << endl << "after sort..." << endl;

    for (std::vector<Student_info>::iterator i = students.begin(); i != students.end(); ++i) {
        std::cout << i->name() << ": " << i->grade() << endl;
    }
}