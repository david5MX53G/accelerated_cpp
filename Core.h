//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_CORE_H
#define ACCELERATED_CPP_CORE_H
#include <iostream>
#include <vector>

class Core {
public:
    // constructors
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }

    // other stuff
    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    // accessible to derived classes
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    // accessible only to this class
    std::string n;
};

#endif //ACCELERATED_CPP_CORE_H
