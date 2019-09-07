//
// Created by branch on 9/5/19.
//

#ifndef ACCELERATED_CPP_PTR_H
#define ACCELERATED_CPP_PTR_H

#include <cstddef>
#include "vec.h"
#include <stdexcept>

template <class T>
class Ptr {
public:
    // copy object conditionally when needed
    void make_unique();

    // constructors
    Ptr(): p(0), refptr(new size_t(1)) { }
    Ptr(T* t): p(t), refptr(new size_t(1)) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }
    ~Ptr();

    // operators
    Ptr& operator=(const Ptr&);
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T* p;
    std::size_t* refptr;
};

#endif //ACCELERATED_CPP_PTR_H
