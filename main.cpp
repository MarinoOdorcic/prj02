#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "fmt/core.h"
#include "WaveData.h"
#include "InterpolationPolicies.h"
#include "Interpolator2D.h"


int main() {

    WaveData waveTable;
    waveTable.loadTestData();
    waveTable.loadFullData();
//    waveTable.loadSymmetricData();
//    waveTable.mirrorExtendData();
    waveTable.printTable();

    std::vector<std::vector<double>> data = waveTable.waveHeightData;
    std::vector<double> colHeadings = waveTable.waveDirectionHeading;
    std::vector<double> rowHeadings = waveTable.wavePeriodHeading;

    double x = 67.5;
    double y = 3;

    Interpolator2D< NearestNeighborInterpolation, LinearInterpolation> interpolatorLinearNearest(
            NearestNeighborInterpolation(),
            LinearInterpolation(),
            rowHeadings,
            colHeadings
    );
    Interpolator2D<NearestNeighborInterpolation, CubicInterpolation> interpolatorCubicNearest(
            NearestNeighborInterpolation(),
            CubicInterpolation(),
            rowHeadings,
            colHeadings
    );
    Interpolator2D<LinearInterpolation, NearestNeighborInterpolation> interpolatorNearestLinear(
            LinearInterpolation(),
            NearestNeighborInterpolation(),
            rowHeadings,
            colHeadings
    );
    Interpolator2D<CubicInterpolation, NearestNeighborInterpolation> interpolatorNearestCubic(
            CubicInterpolation(),
            NearestNeighborInterpolation(),
            rowHeadings,
            colHeadings
    );
    Interpolator2D<CubicInterpolation, CubicInterpolation> interpolatorLinearLinear(
            CubicInterpolation(),
            CubicInterpolation(),
            rowHeadings,
            colHeadings
    );
    Interpolator2D<LinearInterpolation, LinearInterpolation> interpolatorCubicCubic(
            LinearInterpolation(),
            LinearInterpolation(),
            rowHeadings,
            colHeadings
    );

    double resultLinearNearest = interpolatorLinearNearest.interpolate(data, x, y);
    double resultCubicNearest = interpolatorCubicNearest.interpolate(data, x, y);
    double resultNearestLinear = interpolatorNearestLinear.interpolate(data, x, y);
    double resultNearestCubic = interpolatorNearestCubic.interpolate(data, x, y);
    double resultLinearLinear = interpolatorLinearLinear.interpolate(data, x, y);
    double resultCubicCubic = interpolatorCubicCubic.interpolate(data, x, y);

    fmt::print("\nInterpolated value at ({}, {}",x,y);
    fmt::print("\nLinear-Nearest:\t{:.5f}", resultLinearNearest);
    fmt::print("\nCubic-Nearest:\t{:.5f}", resultCubicNearest);
    fmt::print("\nNearest-Linear:\t{:.5f}", resultNearestLinear);
    fmt::print("\nNearest-Cubic:\t{:.5f}", resultNearestCubic);
    fmt::print("\nLinear-Linear:\t{:.5f}", resultLinearLinear);
    fmt::print("\nCubic-Cubic:\t{:.5f}", resultCubicCubic);

//    std::cout << "Linear-Nearest Interpolated value at (" << x << ", " << y << "): " << resultLinearNearest << std::endl;
//    std::cout<<std::endl;
//    std::cout << "Cubic Interpolated value at (" << x << ", " << y << "): " << resultCubicNearest << std::endl;



//    double direction = 11.25;
//    double period = 7.5;
//    auto directionV = waveTable.waveDirectionHeading;
//    auto periodV = waveTable.wavePeriodHeading;
//    auto data = waveTable.waveHeightData;
//
//    auto xBounds = findBounds(directionV,direction);
//    auto yBounds = findBounds(periodV,period);
//
//
//    fmt::print("\n{}", xBounds);
//    fmt::print("\n{}", yBounds);
//
//    auto x1 = solve(direction,
//                    directionV[xBounds[0]],
//                    directionV[xBounds[1]],
//                    data[yBounds[0]][xBounds[0]],
//                    data[yBounds[0]][xBounds[1]]);
//    auto x2 = solve(direction,
//                    directionV[xBounds[0]],
//                    directionV[xBounds[1]],
//                    data[yBounds[1]][xBounds[0]],
//                    data[yBounds[1]][xBounds[1]]);
//    auto y = solve(period,
//                   periodV[yBounds[0]],
//                   periodV[yBounds[1]],
//                   x1,
//                   x2);
//
//    fmt::print("\n{}", x1);
//    fmt::print("\n{}", x2);
//    fmt::print("\n{}", y);
    return 0;
}