//
// Created by branch on 8/19/19.
//

#include "Grad.h"

using std::istream;
using std::min;

double Grad::grade() const {
    return min(Core::grade(), thesis);
}