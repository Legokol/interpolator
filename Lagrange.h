#ifndef INTERPOLATOR_LAGRANGE_H
#define INTERPOLATOR_LAGRANGE_H

#include <vector>

using std::vector;

class Lagrange {
public:

    Lagrange(vector<double> x, vector<double> f) : x0(x), f0(f) {}

    double interpolate(double x) {
        vector<double> l(x0.size(), 1);
        double f = 0;
        for (int k = 0; k < l.size(); ++k) {
            for (int i = 0; i < x0.size(); ++i) {
                if (i != k)
                    l[k] *= (x - x0[i]) / (x0[k] - x0[i]);
            }
            f += l[k] * f0[k];
        }
        return f;
    }

private:
    vector<double> x0;
    vector<double> f0;
};


#endif //INTERPOLATOR_LAGRANGE_H
