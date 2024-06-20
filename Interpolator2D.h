#ifndef PRJ02_INTERPOLATOR2D_H
#define PRJ02_INTERPOLATOR2D_H

#include <vector>
#include <algorithm>

#include "InterpolationPolicies.h"

template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
class Interpolator2D {
private:
    RowInterpolationPolicy rowPolicy;
    ColInterpolationPolicy colPolicy;
    std::vector<double> rowHeadings;
    std::vector<double> colHeadings;

    double mapToIndex(const std::vector<double>& headings, double value) const;

public:
    Interpolator2D(RowInterpolationPolicy rowPolicy, ColInterpolationPolicy colPolicy,
                   const std::vector<double>& rowHeadings, const std::vector<double>& colHeadings);

    double interpolate(const std::vector<std::vector<double>>& data, double x, double y) const;
};

#include "Interpolator2D.cpp"


#endif //PRJ02_INTERPOLATOR2D_H
