//
// Created by branch on 8/30/19.
//
#ifndef ACCELERATED_CPP_HANDLE_H
#define ACCELERATED_CPP_HANDLE_H

template <class T>
class Handle {
public:
    // constructs and destrs
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }
    Handle(T* t): p (t) { }

    // operators
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T* p;
};

#endif //ACCELERATED_CPP_HANDLE_H
