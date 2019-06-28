#include "split.h"
#include <vector>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> v = split(s);

        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}
