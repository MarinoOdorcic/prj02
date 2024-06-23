#ifndef PRJ02_INTERPOLATIONPOLICIES_H
#define PRJ02_INTERPOLATIONPOLICIES_H

#include "iostream"
#include <vector>
#include <algorithm>

#include "fmt/core.h"
#include <fmt/format.h>
#include <fmt/ranges.h>

/* ------------------------------------------------------------------------- */
struct LinearInterpolation {
    int pointsRequired = 2;
    double interpolate(const std::vector<double>& header,
                       const std::vector<double>& data,
                       double x,
                       int boundaryType) ;
};

/* ------------------------------------------------------------------------- */
struct NearestNeighborInterpolation {
    int pointsRequired = 2;
    double interpolate(const std::vector<double>& header,
                       const std::vector<double>& data,
                       double x,
                       int boundaryType) ;
};

/* ------------------------------------------------------------------------- */
struct CubicInterpolation {
    int pointsRequired = 4;
    double interpolate(const std::vector<double>& header,
                       const std::vector<double>& data,
                       double x,
                       int boundaryType) ;
};

#endif //PRJ02_INTERPOLATIONPOLICIES_H