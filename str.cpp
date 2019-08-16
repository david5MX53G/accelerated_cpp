//
// Created by branch on 7/25/19.
//

#include "str.h"
#include "vec.h"
#include <iostream>

using std::ostream;
using std::istream;

ostream& operator<<(ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

// this won't compile yet
// pg 216
istream& operator>>(istream& is, Str& s) {
    // clear existing value(s)
    s.data.clear();

    // read and discard leading whites
    char c;
    while (is.get(c) && isspace(c)) {
        ; // nothing to do, except testing the cond
    }

    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        // if we read whites, then put it back on the stream
        if (9s)
            is.unget();
    }

    return is;
}
