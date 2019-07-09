#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "split.h"

using std::cin;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::vector;
using std::istream;

// find all lines referring to each word from input
map<string, vector<int> > xref(
        istream& in,
        vector<string> find_words(const string&) = split // this parameter uses a "default argument"
    ) {
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (getline(in, line)) { // getline() is from the string library
        ++line_number;
        vector<string> words = find_words(line); // function parameter "find_words"
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
            ret[*it].push_back(line_number); // append line_number to value of ret[*it] where *it is key of "ret" map
    }
    return ret;
}

int main() {
    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << it->first << " occurs on line(s): ";
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;
        ++line_it;

        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }

        cout << endl;
    }
    return 0;
}
