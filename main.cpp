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

    double x = 22.5;
    double y = 6;

    fmt::print("\nInterpolated value at ({}, {})\n",x,y);

    Interpolator2D <CubicInterpolation, CubicInterpolation> interpolator;
    double result = interpolator.interpolate(rowHeadings, colHeadings, data, x, y);
//    fmt::print("\nCubic-Cubic:\t{:.5f}", result);

//    Interpolator2D <LinearInterpolation, LinearInterpolation> interpolator2;
//    result = interpolator2.interpolate(rowHeadings, colHeadings, data, x, y);
//    fmt::print("\nLinear-Linear:\t{:.5f}", result);


    return 0;
}