//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_GRAD_H
#define ACCELERATED_CPP_GRAD_H
#include "Core.h"
#include "Student_info.h"
#include <iostream>

class Grad: public Core {
public:
    // constructors
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }

    // other stuff
    double grade() const;

    std::istream& read(std::istream& in) {
        read_common(in);
        in >> thesis;
        read_hw(in, homework);
        return in;
    };
protected:
    Grad* clone() const { return new Grad(*this); }
private:
    double thesis;
};

#endif //ACCELERATED_CPP_GRAD_H
