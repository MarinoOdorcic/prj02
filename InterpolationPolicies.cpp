#include "InterpolationPolicies.h"

/* ---------------------------------------------------------------------------------------------------- */
double LinearInterpolation::interpolate(const std::vector<double>& header,
                                        const std::vector<double>& data,
                                        double x,
                                        int boundaryType) {
    auto it = std::upper_bound(header.begin(), header.end(), x);
    size_t i = it - header.begin();
    if (i == header.size()) i = i - 1;

    auto x0 = header[i - 1];
    auto x1 = header[i];
    auto y0 = data[i-1];
    auto y1 = data[i];

    auto y = y0 + (x-x0) * (y1-y0) / (x1-x0);

    fmt::print("\nV:\t{}", x);
    fmt::print("\nX:\t{}\t{}", x0, x1);
    fmt::print("\nY:\t{}\t{}", y0, y1);
    fmt::print("\nI:\t{}\n", y);
    return y;
}
int LinearInterpolation::pointsRequired() {
    return 2;
}

/* ---------------------------------------------------------------------------------------------------- */
double NearestNeighborInterpolation::interpolate(const std::vector<double>& header,
                                                 const std::vector<double>& data,
                                                 double x,
                                                 int boundaryType) {
    auto it = std::upper_bound(header.begin(), header.end(), x);
    size_t i = it - header.begin();
    if (i == header.size()) i = i - 1;

    auto y = data[i];
    if (header[i] - x > x - header[i - 1]){
        y = data[i-1];
    }

    fmt::print("\nV:\t{}", x);
    fmt::print("\nX:\t{}\t{}", data[i-1], data[i]);
    fmt::print("\nY:\t{}\t{}", header[i - 1], header[i]);
    fmt::print("\nI:\t{}\n", y);
    return y;
}
int NearestNeighborInterpolation::pointsRequired() {
    return 2;
}
/* ---------------------------------------------------------------------------------------------------- */
double CubicInterpolation::interpolate(const std::vector<double>& header,
                                       const std::vector<double>& data,
                                       double x,
                                       int boundaryType) {
    auto it = std::upper_bound(header.begin(), header.end(), x);
    size_t index = it - header.begin();
    if (index==header.size()) index = index-2;

    double x0, x1, x2, x3;
    double y0, y1, y2, y3;

    x1 = header[index - 1];
    x2 = header[index];
    y1 = data[index - 1];
    y2 = data[index];

    fmt::print("{}", fmt::join(header, " "));
    fmt::print("\n{} ",header[3]);

    if (boundaryType == 0){
        x0 = header[index - 2];
        x3 = header[index + 1];
        y0 = data[index - 2];
        y3 = data[index + 1];

    } else if (boundaryType == 1){
        if (index == 1) {

            x0 = header[header.size() - 2] - 360;
            y0 = data[data.size()-2];
        } else {
            x0 = header[index - 2];
            y0 = data[index - 2];
        }
        if (index == data.size()-1){
            x3 = header[1] + 360;
            y3 = data[1];
        } else {
            x3 = header[index + 1];
            y3 = data[index + 1];
        }

    } else {
        if (index == 2) {
            x0 = header[index-1]*2 - header[index];
            y0 = data[index-1]*2 - data[index];
        } else {
            x0 = header[index - 2];
            y0 = data[index - 2];
        }
        if (index == data.size()-2){
            fmt::print("\n{}",header[index]);
            x3 = header[index]*2 - header[index-1];
            y3 = data[index]*2 - data[index-1];
        } else {
            x3 = header[index + 1];
            y3 = data[index + 1];
        }
    }

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

    fmt::print("\nV:\t{}", x);
    fmt::print("\nX:\t{:.8g}\t{}\t{}\t{:.8g}", x0, x1, x2, x3);
    fmt::print("\nY:\t{:.8g}\t{}\t{}\t{:.8g}", y0, y1, y2, y3);
    fmt::print("\nI:\t{:.8g}\n", y);
    return y;
}
int CubicInterpolation::pointsRequired() {
    return 4;
}
