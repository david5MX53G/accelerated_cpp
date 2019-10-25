//
// Created by branch on 9/5/19.
//

#include "Ptr.h"

template<class T>
T& Ptr<T>::operator*() const {
    if (p)
        return *p;
}

template <class T> T* clone(const T* tp) {
    return tp->clone();
}

template <class T> 
void Ptr<T>::make_unique() {
    if (*refptr != 1) {
        --*refptr;
        refptr = new size_t(1);
        p = p? clone(p): 0;
    }
}

template<>
Vec<char>* clone(const Vec<char>* vp) {
    return new Vec<char>(*vp);
}
