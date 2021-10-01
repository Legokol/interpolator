#ifndef INTERPOLATOR_NEWTON_H
#define INTERPOLATOR_NEWTON_H

#include <vector>

using std::vector;

template <typename T>
class Newton {
public:

    Newton(vector<T> x, vector<T> f) : x0(x) {
        vector<vector<T>> dd(x0.size());
        a.resize(x0.size());
        a[0] = f[0];
        dd[0] = f;
        for (int k = 1; k < x0.size(); ++k) {
            dd[k].resize(dd[k - 1].size() - 1);
            for (int i = 0; i < dd[k].size(); ++i) {
                dd[k][i] = (dd[k - 1][i+1] - dd[k - 1][i]) / (x0[i + k] - x0[i]);
            }
            a[k] = dd[k][0];
        }
    }

    T interpolate(T x) {
        T f = a[0];
        for (int k = 1; k < a.size(); ++k) {
            T d = a[k];
            for (int i = 0; i < k; ++i) {
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


#endif //INTERPOLATOR_NEWTON_H
