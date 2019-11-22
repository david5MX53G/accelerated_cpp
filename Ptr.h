//
// Created by branch on 9/5/19.
//

#ifndef ACCELERATED_CPP_PTR_H
#define ACCELERATED_CPP_PTR_H

#include <cstddef>
#include "vec.h"
#include <stdexcept>
#include <iostream>

template <class T>
class Ptr {
public:
    // copy object conditionally when needed
    void make_unique();

    // constructors
    Ptr(): p(0), refptr(new size_t(1)) { }
    Ptr(T* t): p(t), refptr(new size_t(1)) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }

    ~Ptr() {
        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }
    }

    // operators
    Ptr<T>& operator=(const Ptr<T>& ptr) {
        ++*ptr.refptr;

        // free left-hand side, destroying pointers where appropriate
        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }

        // copy in values from the right-hand side
        refptr = ptr.refptr;
        p = ptr.p;
        return *this;
    };

    operator bool() const { return p; }
    T& operator*() const;

    T* operator->() const {
        if (p) {
            return p;
        }
        throw std::runtime_error("unbound Ptr!!!");
    }

private:
    T* p;
    std::size_t* refptr;
};

#endif //ACCELERATED_CPP_PTR_H
