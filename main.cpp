#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
#include "vec.h"
#include <vector>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::cerr;

int main(int argc, char** argv) {
    istringstream ss1(argv[1]);
    int x;
    if (!(ss1 >> x)) {
        cerr << "Invalid int: " << argv[1] << endl;
    } else if (!ss1.eof()) {
        cerr << "Trailing chars after int: " << argv[1] << endl;
    }

    int y;
    istringstream ss2(argv[2]);
    if (!(ss2 >> y)) {
        cerr << "Invalid int: " << argv[2] << endl;
    } else if (!ss2.eof()) {
        cerr << "Trailing chars after int: " << argv[2] << endl;
    }

    Vec<int> v = Vec<int>(x, y);
    for (int i = 0; i != v.size(); i++) {
       cout << v[i] << endl;
    }
    return 0;
}

#pragma clang diagnostic pop