#include "Lagrange.h"
#include "Newton.h"
#include <iostream>

using namespace std;

int main() {
    vector<double> x = {-1, 0, 1, 2};
    vector<double> f = {-1, 0, 1, 8};
    Newton<double> interpolator(x, f);
    cout << interpolator.interpolate(4) << endl;
    return 0;
}