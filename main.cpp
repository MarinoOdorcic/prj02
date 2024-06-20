#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "fmt/core.h"
#include "WaveData.h"
#include "Interpolator.h"
#include "Linear.h"


std::vector<int> findBounds(std::vector<double> vec, double target) {

    auto upper = std::upper_bound(vec.begin(), vec.end(), target); // First element greater than target
    int upperIndex = static_cast<int>(std::distance(vec.begin(), upper));
    int lowerIndex = upperIndex-1;
    return {lowerIndex, upperIndex};
}

double solve(double x, double x1, double x2, double y1, double y2){
    return y1 + ((x - x1) * (y2 - y1)) / (x2 - x1);}


int main() {

    WaveData waveTable;
//    waveTable.loadFullData();
    waveTable.loadSymmetricData();
    waveTable.mirrorExtendData();
    waveTable.printTable();

//    Interpolator<Linear, Linear> interpolator(waveTable.waveDirectionHeading,
//                                              waveTable.wavePeriodHeading,
//                                              waveTable.waveHeightData);


    std::vector<double> x = {1,2,3};
//    Interpolator<Linear, Linear> interpolator(x);





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