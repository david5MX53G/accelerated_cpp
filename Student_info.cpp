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

// copy from Student_info to new Student_info
Student_info::Student_info(const Student_info& s): cp(0) {
    if (s.cp) cp = s.cp->clone();
}

// assign one Student_info to another
Student_info& Student_info::operator=(const Student_info& s) {
   if (&s != this) {
       delete cp;
       if (s.cp)
           cp = s.cp->clone();
       else
           cp = o;

       return *this;
   }
}