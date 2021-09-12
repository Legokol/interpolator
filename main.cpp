#include "Lagrange.h"
#include "Newton.h"
#include <iostream>

using namespace std;

int main() {
    vector<double> x = {-1, 0, 1};
    vector<double> f = {-1, 0, 1};
    Lagrange interpolator(x, f);
    cout << interpolator.interpolate(2) << endl;
    return 0;
}