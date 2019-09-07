//
// Created by branch on 9/4/19.
//

#ifndef ACCELERATED_CPP_REF_HANDLE_H
#define ACCELERATED_CPP_REF_HANDLE_H
#include <cstddef>
#include <stdexcept>

template <class T>
class Ref_handle {
public:
    // constructors
    Ref_handle(): p(0), refptr(new std::size_t(1)) { }
    Ref_handle(T* t): p(t), refptr(new std::size_t(1)) { }
    Ref_handle(const Ref_handle& h): p(h.p), refptr(h.refptr) {
        ++*refptr;
    }

    // destructor
    ~Ref_handle();

    // operators
    Ref_handle& operator=(const Ref_handle&);
    operator bool() const { return p; }
    T operator*() const {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ref_handle");
    }

    T* operator->() const {
        if (p)
            return p;
        throw std::runtime_error("unbound Ref_handle");
    }
private:
    T* p;
    std::size_t* refptr;
};


#endif //ACCELERATED_CPP_REF_HANDLE_H
