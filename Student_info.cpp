#include "Student_info.h"

using std::istream;

// initialize Student_info from istream
istream& Student_info::read(istream& is) {
    char ch; is >> ch; // get record type char

    // allocate the right kind of object
    if (ch == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grad(is);
    }

    return is;
}

// assign one Student_info to another
