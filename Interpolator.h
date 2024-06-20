#ifndef PRJ02_INTERPOLATOR_H
#define PRJ02_INTERPOLATOR_H

#include "iostream"
#include "vector"

#include "WaveData.h"
#include "Linear.h"


template <typename ColInterpolation, typename RowInterpolation>
class Interpolator {
private:
    std::vector<double> row;
    std::vector<double> column;
    std::vector<std::vector<double>> data;
public:
//    explicit Interpolator(std::vector<double> rowHeading,
//                          std::vector<double> columnHeading,
//                          std::vector<std::vector<double>> dataArray);

    Interpolator(std::vector<double> x);

//    int findUpperBound(std::vector<int>& vec, int target);
//
//    double interpolate(double x, double y);





};




#endif //PRJ02_INTERPOLATOR_H
