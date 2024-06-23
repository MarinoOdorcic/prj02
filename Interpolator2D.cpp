#ifndef PRJ02_INTERPOLATOR2D_CPP
#define PRJ02_INTERPOLATOR2D_CPP

#include "Interpolator2D.h"

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
double Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::interpolate(
        std::vector<double>& rowHeadings,
        std::vector<double>& colHeadings,
        std::vector<std::vector<double>>& data,
        double x,
        double y){

    direction = x;

    while (direction<0) direction = direction + 360;
    while (direction>=360) direction = direction - 360;
    if (y<rowHeadings.front() or y>rowHeadings.back())
        throw std::invalid_argument("Wave period out of bounds");


    for (auto &row: data) row.push_back(row[0]);
    colHeadings.push_back(360);

    auto it = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    size_t rowPosition = it - rowHeadings.begin();
    it = std::upper_bound(colHeadings.begin(), colHeadings.end(), x);
    size_t colPosition = it - colHeadings.begin();

    auto colPointsNumber = colPolicy.pointsRequired();
    auto rowPointsNumber = rowPolicy.pointsRequired();


    std::vector<double> rowInterpolations(colPointsNumber,0);
    std::vector<double> rowInterpolationsHeadings(colPointsNumber,0);

    if (rowPosition==rowHeadings.size()) rowPosition = rowPosition-1;

    for (int iter = 0; iter < colPointsNumber; iter++) {
        int index = rowPosition - colPointsNumber / 2 + iter;
        if (index >= 0 && index < rowHeadings.size()) {
            rowInterpolationsHeadings[iter] = rowHeadings[index];
            rowInterpolations[iter] = rowPolicy.interpolate(colHeadings, data[index], direction, 1);
        } else {
            rowInterpolationsHeadings[iter] = 0;
            rowInterpolations[iter] = 0;
        }
    }


    height = colPolicy.interpolate(rowInterpolationsHeadings, rowInterpolations, y, 2);
    return height;
}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
void Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::print(){
    fmt::print("\n{}",std::string(40, '-'));
    fmt::print("\nIncoming wave direction:\t{:.5g}", direction);
    fmt::print("\nIncoming wave height:\t\t{:.5g}", height);
}

#endif //PRJ02_INTERPOLATOR2D_CPP