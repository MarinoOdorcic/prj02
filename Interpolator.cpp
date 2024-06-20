#include "Interpolator.h"

#include <utility>


/* ----- Constructors --------------------------------------- */
//template<typename ColInterpolation, typename RowInterpolation>
//Interpolator<ColInterpolation, RowInterpolation>::Interpolator(std::vector<double> rowHeading,
//                                                               std::vector<double> columnHeading,
//                                                               std::vector<std::vector<double>> dataArray) {
//    row = std::move(rowHeading);
//    column = std::move(columnHeading);
//    data = std::move(dataArray);
//}

template<typename ColInterpolation, typename RowInterpolation>
Interpolator<ColInterpolation, RowInterpolation>::Interpolator(std::vector<double> x) {
    row = std::move(x);
}


//template <typename ColInterpolation, typename RowInterpolation>
//int Interpolator<ColInterpolation, RowInterpolation>::findUpperBound(std::vector<int>& vec, int target){
//    auto upper = std::upper_bound(vec.begin(), vec.end(), target);
//    int upperIndex = static_cast<int>(std::distance(vec.begin(), upper));
//    return upperIndex;
//}
//
//template <typename ColInterpolation, typename RowInterpolation>
//double Interpolator<ColInterpolation, RowInterpolation>::interpolate(double x, double y){
//    double x1 = ColInterpolation::template interpolate<double>(x, row, data[5]);
//    return x1;
//}



