#ifndef ACCELERATED_CPP_STUDENT_INFO_H
#define ACCELERATED_CPP_STUDENT_INFO_H
#include <iostream>
#include <string>
#include <vector>
#include "Core.h"
#include "Grad.h"

class Student_info {
public:
    // constructors and copy control
    Student_info(): cp(0) { }
    Student_info(std::istream& is): cp(0) { read(is); }

    // operations
    std::istream& read(std::istream&);

    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }
private:
    Handle<Core> cp;
};

#endif
