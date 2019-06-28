//
// Created by branch on 6/28/19.
//

#include "split.h"
#include <vector>

using std::vector;

// split string into space-delim words and return resulting vector
vector<string> split(const string& s) {
   vector<string> ret;
   typedef string::size_type string_size;
   string_size i = 0;

   // invariant: we have processed characters
   while (i != s.size()) {
       // invariant: characters in range are all spaces
       while (i != s.size() && isspace(s[i]))
           ++i;

       // find end of next word
       string_size j = i;
       // invariant: none of the characters in range is a space
       while (j != s.size() && !isspace(s[j]))
           ++j;

       // if we have non-whitespace chars
       if (i != j) {
           ret.push_back(s.substr(i, j - i));
           i = j;
       }
   }
   return ret;
}
