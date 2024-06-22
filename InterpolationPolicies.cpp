#include "InterpolationPolicies.h"

/* ---------------------------------------------------------------------------------------------------- */
double LinearInterpolation::interpolate(const std::vector<double>& heading,
                                        const std::vector<double>& data,
                                        double x) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), x);
    size_t i = it - heading.begin();
    if (i==heading.size()) i = i-1;

    auto x0 = heading[i-1];
    auto x1 = heading[i];
    auto y0 = data[i-1];
    auto y1 = data[i];
    auto y = y0 + (x-x0) * (y1-y0) / (x1-x0);
    return y;
}
int LinearInterpolation::pointsRequired() {
    return 2;
}

/* ---------------------------------------------------------------------------------------------------- */
double NearestNeighborInterpolation::interpolate(const std::vector<double>& heading,
                                                 const std::vector<double>& data,
                                                 double x) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), x);
    size_t i = it - heading.begin();
    if (i==heading.size()) i = i-1;

    auto y = data[i];
    if (heading[i]-x > x-heading[i-1]){
        y = data[i-1];
    }
    return y;
}
int NearestNeighborInterpolation::pointsRequired() {
    return 2;
}
/* ---------------------------------------------------------------------------------------------------- */
double CubicInterpolation::interpolate(const std::vector<double>& heading,
                                       const std::vector<double>& data,
                                       double x) const {
    auto it = std::upper_bound(heading.begin(), heading.end(), x);
    int index = static_cast<int>(std::distance(heading.begin(), it));

    auto x0 = heading[index - 2];
    auto x1 = heading[index - 1];
    auto x2 = heading[index];
    auto x3 = heading[index + 1];

    auto y0 = data[index - 2];
    auto y1 = data[index - 1];
    auto y2 = data[index];
    auto y3 = data[index + 1];

    auto m0 = (y1 - y0) / (x1 - x0);
    auto m1 = (y2 - y1) / (x2 - x1);
    auto m2 = (y3 - y2) / (x3 - x2);

    auto s1 = (m0+m1)/2;
    auto s2 = (m1+m2)/2;

    auto a = y1;
    auto b = s1;
    auto c = (3*m1-2*s1-s2)/(x2-x1);
    auto d = (s1+s2-2*m1)/((x2-x1)*(x2-x1));

    auto y = a + b*(x-x1) + c*(x-x1)*(x-x1) + d*(x-x1)*(x-x1)*(x-x1);
    return y;
}
int CubicInterpolation::pointsRequired() {
    return 4;
}