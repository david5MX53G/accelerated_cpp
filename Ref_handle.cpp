//
// Created by branch on 9/4/19.
//

#include "Ref_handle.h"
template <class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs) {
    ++*rhs.refptr;

    // free left-hand arg, destroying pointers
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // copy values from right to left
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T>
Ref_handle<T>::~Ref_handle() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}
