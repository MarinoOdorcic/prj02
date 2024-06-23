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
    while (direction>=360) direction = direction - 360;
    if (y<rowHeadings.front() or y>rowHeadings.back())
        throw std::invalid_argument("Wave period out of bounds");


    for (auto &row: data) row.push_back(row[0]);
    colHeadings.push_back(360);

    auto it = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    size_t i = it - rowHeadings.begin();
    it = std::upper_bound(colHeadings.begin(), colHeadings.end(), y);
    size_t j = it - colHeadings.begin();

    auto nc = colPolicy.pointsRequired();
    auto nr = rowPolicy.pointsRequired();



    std::vector<double> rowInterpolations(nc,0);
    std::vector<double> rowInterpolationsHeadings(nc,0);
    if (i==rowHeadings.size()) i = i-1;
    for(int r = 0; r<nc; r++){
        int index = i - nc/2 + r;
        if (index>=1 or index<=rowHeadings.size()-1){
            rowInterpolationsHeadings[r] = rowHeadings[index];
            if (nr == 4 and (j == colHeadings.size() or j == 1)) {
                rowPolicy.setBoundaryType(1);
            }
            rowInterpolations[r] = rowPolicy.interpolate(colHeadings, data[index], direction);
        }
    }

    if (nc==4 and (i==colHeadings.size() or i==1)){
        colPolicy.setBoundaryType(2);
    }
    height = colPolicy.interpolate(rowInterpolationsHeadings, rowInterpolations, y);
    return height;
}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
void Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::print(){
    fmt::print("\n{}",std::string(40, '-'));
    fmt::print("\nIncoming wave direction:\t{:.5g}", direction);
    fmt::print("\nIncoming wave height:\t\t{:.5g}", height);
}

#endif //PRJ02_INTERPOLATOR2D_CPP