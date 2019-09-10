//
// Created by branch on 8/30/19.
//
#ifndef ACCELERATED_CPP_HANDLE_H
#define ACCELERATED_CPP_HANDLE_H

#include <system_error>

template <class T>
class Handle {
public:
    // constructors
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) {
        if (s.p) p = s.p->clone();
    }

    Handle& operator=(const Handle& rhs) {
        if (&rhs != this) {
            delete p;
            p = rhs.p ? rhs.p->clone() : 0;
        }
        return *this;
    };

    ~Handle() { delete p; }
    Handle(T* t): p (t) { }

    // operators
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const {
        if (p)
            return p;
        throw std::runtime_error("unbound Handle");
    };
private:
    T* p;
};

#endif //ACCELERATED_CPP_HANDLE_H
