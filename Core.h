//
// Created by branch on 8/19/19.
//

#ifndef ACCELERATED_CPP_CORE_H
#define ACCELERATED_CPP_CORE_H
#include <iostream>
#include <vector>
#include "Handle.h"

class Core {
    friend class Student_info;
public:
    // (de-)constructors
    virtual ~Core() { }
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); }

    // other stuff
    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    // accessible to derived classes
    virtual Core* clone() const { return new Core(*this); }
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    // accessible only to this class
    std::string n;
};

bool compare_Core_ptrs(const Core*, const Core*);

bool compare_Core_Handles(const Handle<Core>& hc1, const Handle<Core>& hc2) {
    return hc1.p->name() < hc2.p->name();
}


#endif //ACCELERATED_CPP_CORE_H
