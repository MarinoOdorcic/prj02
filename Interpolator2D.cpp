#ifndef PRJ02_INTERPOLATOR2D_CPP
#define PRJ02_INTERPOLATOR2D_CPP

#include "Interpolator2D.h"

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::Interpolator2D(){}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
double Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::interpolate(
        const std::vector<double>& rowHeadings,
        const std::vector<double>& colHeadings,
        const std::vector<std::vector<double>>& data,
        double x,
        double y) const {

    auto it = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    size_t i = it - rowHeadings.begin();
    auto n = colPolicy.pointsRequired();


    std::vector<double> rowInterpolations(n);
    std::vector<double> rowInterpolationsHeadings(n);
    for(int r = 0; r<n; r++){
        int index = i - n/2 + r;
        rowInterpolationsHeadings[r] = rowHeadings[index];
        rowInterpolations[r] = rowPolicy.interpolate(colHeadings, data[index], x);
    }
    double res = colPolicy.interpolate(rowInterpolationsHeadings, rowInterpolations, y);
//    fmt::print("{}", fmt::format("{:<{}.4g}", fmt::join(rowInterpolationsHeadings, ""), width));
    fmt::print("Row:\t{:.5g}\n", fmt::join(rowInterpolations, " "));
    fmt::print("Col:\t{:.5g}\n", res);

    return res;
}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
void Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::print(){

}

#endif //PRJ02_INTERPOLATOR2D_CPP