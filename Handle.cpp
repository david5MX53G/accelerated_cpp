//
// Created by branch on 8/30/19.
//

#include "Handle.h"

using std::runtime_error;

template <class T>
T& Handle<T>::operator*() const {
    if (p)
        return *p;
    throw runtime_error("unbound Handle");
}
