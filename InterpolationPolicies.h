#ifndef PRJ02_INTERPOLATIONPOLICIES_H
#define PRJ02_INTERPOLATIONPOLICIES_H

#include "iostream"
#include <vector>
#include <algorithm>

/* ------------------------------------------------------------------------- */
struct LinearInterpolation {
    double interpolate(const std::vector<double>& data, double position) const;
};

/* ------------------------------------------------------------------------- */
struct NearestNeighborInterpolation {
    double interpolate(const std::vector<double>& data, double position) const;
};

/* ------------------------------------------------------------------------- */
struct CubicInterpolation {
    double interpolate(const std::vector<double>& data, double position) const;
};

#endif //PRJ02_INTERPOLATIONPOLICIES_H