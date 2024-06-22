#ifndef PRJ02_INTERPOLATOR2D_H
#define PRJ02_INTERPOLATOR2D_H

#include <vector>
#include <algorithm>

#include "fmt/core.h"
#include <fmt/format.h>
#include <fmt/ranges.h>

#include "InterpolationPolicies.h"


template <typename RowInterpolationPolicy, typename ColInterpolationPolicy>
class Interpolator2D {
private:
    RowInterpolationPolicy rowPolicy;
    ColInterpolationPolicy colPolicy;

public:
    Interpolator2D();

    double interpolate( const std::vector<double>& rowHeadings,
                        const std::vector<double>& colHeadings,
                        const std::vector<std::vector<double>>& data,
                        double x,
                        double y) const;
    void print();
};

#include "Interpolator2D.cpp"
#endif //PRJ02_INTERPOLATOR2D_H
