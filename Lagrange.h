#ifndef INTERPOLATOR_LAGRANGE_H
#define INTERPOLATOR_LAGRANGE_H

#include <vector>

using std::vector;

class Lagrange {
public:

    Lagrange(vector<double> x, vector<double> f) : x0(x) {
        a.resize(x0.size());
        for (int k = 0; k < a.size(); ++k) {
            a[k] = f[k];
            for (int i = 0; i < a.size(); ++i) {
                if (i != k) {
                    a[k] /= (x0[k] - x0[i]);
                }
            }
        }
    }

    double interpolate(double x) {
        double f = 0;
        for (int k = 0; k < a.size(); ++k) {
            double d = a[k];
            for (int i = 0; i < x0.size(); ++i) {
                if (i != k)
                    d *= (x - x0[i]);
            }
            f += d;
        }
        return f;
    }

private:
    vector<double> x0;
    vector<double> a;
};


#endif //INTERPOLATOR_LAGRANGE_H
