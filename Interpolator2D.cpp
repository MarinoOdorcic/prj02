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
    if (y<rowHeadings.front() or y>rowHeadings.back())
        throw std::invalid_argument("Wave period out of bounds");


    for (auto &row: data) row.push_back(row[0]);
    colHeadings.push_back(360);

    auto it = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    size_t i = it - rowHeadings.begin();

    auto nc = colPolicy.pointsRequired();



    if (nc == 4){
        if (i==1){
            rowHeadings.insert(rowHeadings.begin(), rowHeadings[0]*2-rowHeadings[1]);
            data.insert(data.begin(), std::vector<double>(data[0].size(),0));
            for (size_t k = 0; k < data[0].size(); ++k) {
                data[0][k] = (data[1][k] * 2) - data[2][k];
            }
        }
        if (i==rowHeadings.size()){
            rowHeadings.push_back(rowHeadings[i-1]*2-rowHeadings[i-2]);
            data.emplace_back(data[0].size(),0);
            for (size_t k = 0; k < data[0].size(); ++k) {
                data[i][k] = (data[i-1][k] * 2) - data[i-2][k];
            }
        }
    }


    fmt::print("\n{:.8g}", fmt::join(rowHeadings, " "));
    for (int h=0; h<data.size();++h) fmt::print("\n{:.8g}", fmt::join(data[h], " "));



    std::vector<double> rowInterpolations(nc);
    std::vector<double> rowInterpolationsHeadings(nc);
    if (i==rowHeadings.size()) i = i-1;
    for(int r = 0; r<nc; r++){
        int index = i - nc/2 + r;

        fmt::print("\n------{}",index);
        fmt::print("\n{:.8g}", fmt::join(data[index], " "));

        rowInterpolationsHeadings[r] = rowHeadings[index];
        rowInterpolations[r] = rowPolicy.interpolate(colHeadings, data[index], direction);
    }

    fmt::print("\nRowH:\t{}", fmt::join(rowInterpolationsHeadings, " "));

    auto jt = std::upper_bound(rowHeadings.begin(), rowHeadings.end(), y);
    height = colPolicy.interpolate(rowInterpolationsHeadings, rowInterpolations, y);


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