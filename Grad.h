//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_GRAD_H
#define ACCELERATED_CPP_GRAD_H
#include <iostream>

class Grad: public Core {
public:
    Grad();
    Grad(std::istream&);
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
};


#endif //ACCELERATED_CPP_GRAD_H
