#include "Linear.h"

double Linear::solve(double x, std::vector<double> xVec, std::vector<double> yVec){

    auto position = std::upper_bound(xVec.begin(), xVec.end(), x);
    int i = static_cast<int>(std::distance(xVec.begin(), position));

    double x2 = xVec[i];
    double x1 = xVec[i-1];
    double y2 = yVec[i];
    double y1 = yVec[i-1];

    return y1 + ((x - x1) * (y2 - y1)) / (x2 - x1);
};







