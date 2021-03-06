#include "lib/googletest/include/gtest/gtest.h"
#include <fstream>
#include "Core.cpp"
#include "Grad.cpp"
#include "grade.cpp"
#include "median.cpp"
#include <filesystem>
#include <iostream>
#include "Ptr.cpp"
#include "Ptr.h"
#include "Picture.cpp"

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

TEST(acceleratedCppTestSuite, pictureVcatTest) {
    vector<string> v0;
    v0.push_back("this ");
    v0.push_back("is ");
    v0.push_back("the ");
    Picture p0(v0);

    vector<string> v1;
    v1.push_back("forest ");
    v1.push_back("primeval ");
    Picture p1(v1);

    std::cout << endl << vcat(p0, p1);
}

TEST(acceleratedCppTestSuite, pictureHcatTest) {
    vector<Student_info> students;
    Student_info s;

    ifstream ifs;
    ifs.open("../../students.txt", std::ifstream::out);

    if (ifs.is_open()) {
        while (s.read(ifs)) {
            students.push_back(s);
        }
        ifs.close();
    }

    vector<string> names;
    vector<string> grades;

    for (std::vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        names.push_back(it->name());
        grades.push_back(" " + string(it->grade()/5,'='));
    }

    std::cout << endl << hcat(names, grades);
}

TEST(acceleratedCppTestSuite, pictureFrameTest) {
    vector<Student_info> students;
    Student_info s;

    ifstream ifs;
    ifs.open("../../students.txt", std::ifstream::out);

    if (ifs.is_open()) {
        while (s.read(ifs)) {
            students.push_back(s);
        }
        ifs.close();
    }

    vector<string> names;
    vector<string> grades;

    for (std::vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        names.push_back(it->name());
        grades.push_back(" " + string(it->grade()/5,'='));
    }

    std::cout << endl << frame(hcat(names, grades));
}

TEST(acceleratedCppTestSuite, histogramTest) {
   vector<Student_info> students;
   Student_info s;

   ifstream ifs;
   ifs.open("../../students.txt", std::ifstream::out);

   if (ifs.is_open()) {
       while (s.read(ifs)) {
           students.push_back(s);
       }
       ifs.close();
   }

   std::cout << endl << histogram(students);
}

TEST(acceleratedCppTestSuite, studentTest) {
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