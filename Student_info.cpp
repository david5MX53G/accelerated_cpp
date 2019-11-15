#include <string>
#include "Grad.h"

using std::istream;

class Student_info {
public:
    // constructors and copy control
    Student_info() { }
    Student_info(std::istream& is) { read(is); }

    // initialize Student_info from istream
    std::istream& read(std::istream& is) {
        char ch; is >> ch; // get record type char

        // allocate the right kind of object
        if (ch == 'U') {
            cp = new Core(is);
        } else {
            cp = new Grad(is);
        }

        return is;
    }

    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }
private:
    Handle<Core> cp;
};
