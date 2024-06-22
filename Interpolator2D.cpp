#ifndef PRJ02_INTERPOLATOR2D_CPP
#define PRJ02_INTERPOLATOR2D_CPP

#include "Interpolator2D.h"

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::Interpolator2D(){}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
double Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::interpolate(
        std::vector<double>& rowHeadings,
        std::vector<double>& colHeadings,
        std::vector<std::vector<double>>& data,
        double x,
        double y){
    direction = x;

    while (direction<0) direction = direction + 360;
    while (direction>360) direction = direction - 360;


    for (auto &row: data) row.push_back(row[0]);
    colHeadings.push_back(360);

    auto it = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    size_t i = it - rowHeadings.begin();

    auto n = colPolicy.pointsRequired();
    std::cout<<i;

    std::vector<double> rowInterpolations(n);
    std::vector<double> rowInterpolationsHeadings(n);

    if (i==rowHeadings.size()) i = i-1;
    for(int r = 0; r<n; r++){
        int index = i - n/2 + r;
        rowInterpolationsHeadings[r] = rowHeadings[index];
        rowInterpolations[r] = rowPolicy.interpolate(colHeadings, data[index], direction);
    }

    auto jt = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    height = colPolicy.interpolate(rowInterpolationsHeadings, rowInterpolations, y);

    fmt::print("\nColH:\t{}", fmt::join(data, " "));
    fmt::print("\nRowH:\t{}", fmt::join(rowInterpolationsHeadings, " "));
    fmt::print("\nRow:\t{:.8g}", fmt::join(rowInterpolations, " "));
    fmt::print("\nCol:\t{:.8g}", height);

    return height;
}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
void Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::print(){
    fmt::print("\n{}",std::string(40, '-'));
    fmt::print("\nIncoming wave direction:\t{:.5g}", direction);
    fmt::print("\nIncoming wave height:\t\t{:.5g}", height);
}

#endif //PRJ02_INTERPOLATOR2D_CPP