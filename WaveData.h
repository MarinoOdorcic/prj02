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
    double waveDirection;
    double wavePeriod;
    std::vector<double> waveDirectionHeader;
    std::vector<double> wavePeriodHeader;
    std::vector<std::vector<double>> waveHeightData;
public:
    /* ----- Constructors --------------------------------------- */
    WaveData(double angle, double period);
    /* ----- Get Variable --------------------------------------- */
    double getDirection() const;
    double getPeriod() const;
    std::vector<double> getDirectionHeader();
    std::vector<double> getPeriodHeader();
    std::vector<std::vector<double>> getHeightData();
    /* ----- Functions ------------------------------------------ */
    void loadFullData();
    void loadSymmetricData();
    void loadTestData();
    void mirrorExtendData();
    void printTable();

};

#endif //PRJ02_WAVEDATA_H
