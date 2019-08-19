//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_CORE_H
#define ACCELERATED_CPP_CORE_H
#include <iostream>

class Core {
public:
    Core();
    Core(std::istream&);
    std::string name() const;
    std::istream& read(std::istream&);
    double grade() const;
private:
    std::istream& read_common(std::istream&);
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};


#endif //ACCELERATED_CPP_CORE_H
