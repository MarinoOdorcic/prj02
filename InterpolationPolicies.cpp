#include "InterpolationPolicies.h"

/* ---------------------------------------------------------------------------------------------------- */
double LinearInterpolation::interpolate(const std::vector<double>& data, double position) const {
    int left = static_cast<int>(position);
    int right = left + 1;
    if (right >= data.size()) {
        return data[left];
    }
    double t = position - left;
    return (1 - t) * data[left] + t * data[right];
}

/* ---------------------------------------------------------------------------------------------------- */
double NearestNeighborInterpolation::interpolate(const std::vector<double>& data, double position) const {
    int index = static_cast<int>(position + 0.5);
    if (index >= data.size()) {
        index = data.size() - 1;
    }
    return data[index];
}

/* ---------------------------------------------------------------------------------------------------- */
double CubicInterpolation::interpolate(const std::vector<double>& data, double position) const {
    int size = static_cast<int>(data.size());
    int i = static_cast<int>(position);

    int x0 = std::max(0, std::min(size - 1, i - 1));
    int x1 = std::max(0, std::min(size - 1, i));
    int x2 = std::max(0, std::min(size - 1, i + 1));
    int x3 = std::max(0, std::min(size - 1, i + 2));

//    std::cout<<data[x0]<<std::endl;
//    std::cout<<data[x1]<<std::endl;
//    std::cout<<data[x2]<<std::endl;
//    std::cout<<data[x3]<<std::endl;

//    double t = position - i1;

//    double a0 = data[i1];
//    double d0 = (data[i2] - data[i0]) / 2.0;
//    double d1 = (data[i3] - data[i1]) / 2.0;
//    double a1 = d0 + d1 - 2.0 * (data[i2] - data[i1]);
//
//    return a0 + t * (d0 + t * (a1 + t * d1));
    double x = position;

    double y0 = data[x0];
    double y1 = data[x1];
    double y2 = data[x2];
    double y3 = data[x3];

    double a0 = y1;
    double a1 = (y2-y0)/2;
    double a2 = (4*y2-5*y1-y3+2*y0)/2;
    double a3 = (y3-3*y2+3*y1-y0)/2;

    return a0+a1*(x-x1)+a2*(x-x1)*(x-x1)+a3*(x-x1)*(x-x1)*(x-x1);
}