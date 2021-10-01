#ifndef INTERPOLATOR_LAGRANGE_H
#define INTERPOLATOR_LAGRANGE_H

#include <vector>

using std::vector;

template <typename T>
class Lagrange {
public:

    Lagrange(vector<T> x, vector<T> f) : x0(x) {
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

    T interpolate(T x) {
        T f = 0;
        for (int k = 0; k < a.size(); ++k) {
            T d = a[k];
            for (int i = 0; i < x0.size(); ++i) {
                if (i != k)
                    d *= (x - x0[i]);
            }
            f += d;
        }
        return f;
    }

private:
    vector<T> x0;
    vector<T> a;
};


#endif //INTERPOLATOR_LAGRANGE_H
