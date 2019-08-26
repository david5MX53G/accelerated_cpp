//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_GRAD_H
#define ACCELERATED_CPP_GRAD_H
#include "Core.h"
#include "Student_info.h"

class Grad: public Core {
public:
    // constructors
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }

    // other stuff
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
};

#endif //ACCELERATED_CPP_GRAD_H
