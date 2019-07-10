#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "split.h"
#include <random>

using std::cin;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::domain_error;
using std::logic_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// istream should be in the format <category> word1 word2 word3 etc.
Grammar read_grammar(istream& in) {
   Grammar ret;
   string line;

   while (getline(in, line)) {
       vector<string> entry = split(line);

       if(!entry.empty()) {
           ret[entry[0]].push_back(
               Rule(entry.begin() + 1, entry.end())
           );
       }
   }

   return ret;
}

// is the string surrounded by brackets?
bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return random number less than 'n'
int nrand(int n) {
   if (n <= 0 || n > RAND_MAX)
       throw domain_error("Arg to nrand is out of range");

   const int bucket_size = RAND_MAX / n;
   int r;

   do r = rand() / bucket_size;
   while (r >= n);

   cout << "nrand: " << r << endl;
   cout << "rand: " << rand() << endl;
   cout << "bucket_size: " << bucket_size << endl;

   return r;
}

// expand the second arg using the grammar of the first arg, and store results in third arg
void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate corresponding rule using map.find()
        // using g[word] would insert a new value when no match is found
        Grammar::const_iterator it = g.find(word);

        // map.find() returns the end of the map when no matches are found
        if (it == g.end())
            throw logic_error("empty rule");

        // dereferencing a map variable yeilds a "pair" value which always has "first" and "second" members
        const Rule_collection& c = it->second;

        // select random element of vector from the second value in the Rule_collection pair
        const Rule& r = c[nrand(c.size())];

        // the key to understanding recursion is to understand recursion
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar& g) {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

int main() {
    vector<string> sentence = gen_sentence(read_grammar(cin));
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }

    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}
