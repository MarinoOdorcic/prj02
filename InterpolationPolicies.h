#ifndef PRJ02_INTERPOLATIONPOLICIES_H
#define PRJ02_INTERPOLATIONPOLICIES_H

#include "iostream"
#include <vector>
#include <algorithm>
//#include <cmath>

#include "fmt/core.h"
#include <fmt/format.h>
#include <fmt/ranges.h>
//#include <Eigen/Dense>

/* ------------------------------------------------------------------------- */
struct LinearInterpolation {
    double interpolate(const std::vector<double>& heading,
                       const std::vector<double>& data,
                       double x) const;
    static int pointsRequired();
};

/* ------------------------------------------------------------------------- */
struct NearestNeighborInterpolation {
    double interpolate(const std::vector<double>& heading,
                       const std::vector<double>& data,
                       double x) const;
    static int pointsRequired();
};

/* ------------------------------------------------------------------------- */
struct CubicInterpolation {
    double interpolate(const std::vector<double>& heading,
                       const std::vector<double>& data,
                       double x) const;
    static int pointsRequired();
};

#endif //PRJ02_INTERPOLATIONPOLICIES_H