#include <iostream>
#include <string>

using std::cin; using std::endl; using std::cout; using std::string;

int main()
{
   cout << "What's your name? ";
   string name;
   cin >> name;
   const string greeting = "Hello, " + name + "!";

   // blanks surrounding greeting above and on either side
   const int pad = 1;

   // one blank row above and one below plus a row of stars above and below plus the greeting
   const int rows = pad * 2 + 3;

   // length of greeting string plus 1 space on either side + one star on either side
   const string::size_type cols = greeting.size() + pad * 2 + 2;

   cout << endl;


}
