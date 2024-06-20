#ifndef PRJ02_WAVEDATA_H
#define PRJ02_WAVEDATA_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "fmt/core.h"
#include <fmt/format.h>
#include <fmt/ranges.h>

class WaveData {
private:

public:
    WaveData()= default;

    double shipDirection = 30.;
    double shipHeight = 8;

    double waveDirection = 10.;
    double wavePeriod = 7.5;
    std::vector<double> waveDirectionHeading;
    std::vector<double> wavePeriodHeading;
    std::vector<std::vector<double>> waveHeightData;

    void loadFullData();
    void loadSymmetricData();
    void loadTestData();
    void mirrorExtendData();
    void printTable();

};

#endif //PRJ02_WAVEDATA_H
