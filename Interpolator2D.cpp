#ifndef PRJ02_INTERPOLATOR2D_CPP
#define PRJ02_INTERPOLATOR2D_CPP

#include "Interpolator2D.h"

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::Interpolator2D(
        RowInterpolationPolicy rowPolicy, ColInterpolationPolicy colPolicy,
        const std::vector<double>& rowHeadings, const std::vector<double>& colHeadings)
        : rowPolicy(rowPolicy), colPolicy(colPolicy), rowHeadings(rowHeadings), colHeadings(colHeadings) {}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
double Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::mapToIndex(
        const std::vector<double>& headings, double x) const {
    auto it = std::upper_bound(headings.begin(), headings.end(), x);
    size_t index = it - headings.begin();
    auto y0 = static_cast<double>(index-1);
    auto x0 = headings[index-1];
    auto x1 = headings[index];
    return y0 + (x - x0) / (x1 - x0);
}

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
double Interpolator2D<RowInterpolationPolicy, ColInterpolationPolicy>::interpolate(
        const std::vector<std::vector<double>>& data, double x, double y) const {
    double xIndex = mapToIndex(colHeadings, x);
    double yIndex = mapToIndex(rowHeadings, y);

    std::vector<double> rowInterpolations(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        rowInterpolations[i] = rowPolicy.interpolate(data[i], xIndex);
    }
    return colPolicy.interpolate(rowInterpolations, yIndex);
}

#endif //PRJ02_INTERPOLATOR2D_CPP