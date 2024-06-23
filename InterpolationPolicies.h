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
    double interpolate(const std::vector<double>& header,
                              const std::vector<double>& data,
                              double x) ;
    int pointsRequired();
    void setBoundaryType(int type){};
};

/* ------------------------------------------------------------------------- */
struct NearestNeighborInterpolation {
    double interpolate(const std::vector<double>& header,
                              const std::vector<double>& data,
                              double x) ;
    static int pointsRequired();
    void setBoundaryType(int type){};
};

/* ------------------------------------------------------------------------- */
struct CubicInterpolation {
    double interpolate(const std::vector<double>& header,
                       const std::vector<double>& data,
                       double x) ;
    static int pointsRequired();
    void setBoundaryType(int type);
private:
    int boundaryType = 0;
};

#endif //PRJ02_INTERPOLATIONPOLICIES_H