//
// Created by branch on 7/25/19.
//

#ifndef ACCELERATED_CPP_STR_H
#define ACCELERATED_CPP_STR_H

#include <cstring>
#include "vec.h"

class Str {
public:
    typedef Vec<char>::size_type size_type;

    // constructors
    Str() { }
    Str(size_type n, char c): data(n, c) { }
    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    template <class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    // operators
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    // other
    size_type size() const { return data.size(); }

private:
    Vec<char> data;
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

#endif //ACCELERATED_CPP_STR_H
