#include "WaveData.h"



/* ----- Constructors --------------------------------------- */
WaveData::WaveData(double angle, double period) {
    waveDirection = angle;
    wavePeriod = period;
}

/* ----- Get Variable --------------------------------------- */
double WaveData::getDirection() const {
    return waveDirection;
}
double WaveData::getPeriod() const {
    return wavePeriod;
}
std::vector<double> WaveData::getDirectionHeader() {
    return waveDirectionHeader;
}
std::vector<double> WaveData::getPeriodHeader() {
    return wavePeriodHeader;
}
std::vector<std::vector<double>> WaveData::getHeightData() {
    return waveHeightData;
}

/* ----- Functions ------------------------------------------ */
void WaveData::loadFullData() {
    waveDirectionHeader = {0.000, 10.000, 45.000, 90.000, 135.000, 180.000, 225.000, 270.000, 315.000};
    wavePeriodHeader = {1.000, 2.000, 3.000, 4.000, 6.000, 8.000, 10.000, 12.000};
    waveHeightData = {
            {1.000, 1.022, 1.100, 1.200, 1.300, 1.400, 1.500, 1.600, 1.700},
            {2.000, 2.022, 2.100, 2.200, 2.300, 2.400, 2.500, 2.600, 2.700},
            {3.000, 3.022, 3.100, 3.200, 3.300, 3.400, 3.500, 3.600, 3.700},
            {4.000, 4.022, 4.100, 4.200, 4.300, 4.400, 4.500, 4.600, 4.700},
            {6.000, 6.022, 6.100, 6.200, 6.300, 6.400, 6.500, 6.600, 6.700},
            {8.000, 8.022, 8.100, 8.200, 8.300, 8.400, 8.500, 8.600, 8.700},
            {10.000, 10.022, 10.100, 10.200, 10.300, 10.400, 10.500, 10.600, 10.700},
            {12.000, 12.022, 12.100, 12.200, 12.300, 12.400, 12.500, 12.600, 12.700}
    };
}
/* ---------------------------------------------------------- */
void WaveData::loadSymmetricData() {
    waveDirectionHeader = {0.000, 22.500, 45.000, 67.500, 90.000, 112.500, 135.000, 157.500, 180.000};
    wavePeriodHeader = {7.000, 8.000, 9.000, 10.000, 12.000, 14.000};
    waveHeightData = {
            {9.000, 8.000, 7.000, 6.000, 5.000, 4.000, 3.000, 2.000, 1.000},
            {9.100, 8.100, 7.100, 6.100, 5.100, 4.100, 3.100, 2.100, 1.100},
            {9.200, 8.200, 7.200, 6.200, 5.200, 4.200, 3.200, 2.200, 1.200},
            {9.300, 8.300, 7.300, 6.300, 5.300, 4.300, 3.300, 2.300, 1.300},
            {9.400, 8.400, 7.400, 6.400, 5.400, 4.400, 3.400, 2.400, 1.400},
            {9.500, 8.500, 7.500, 6.500, 5.500, 4.500, 3.500, 2.500, 1.500},
    };
}
/* ---------------------------------------------------------- */
void WaveData::loadTestData() {
    waveDirectionHeader = {1,2,3,4,5};
    wavePeriodHeader = {1,2,3,4};
    waveHeightData = {
            {5,1.0, 2.0, 3.0, 4.0},
            {9,5.0, 6.0, 7.0, 8.0},
            {13,9.0, 10.0, 11.0, 12.0},
            {17,13.0, 14.0, 15.0, 16.0}
    };
}
/* ---------------------------------------------------------- */
void WaveData::mirrorExtendData() {
    int center = static_cast<int>(waveDirectionHeader.size());

    waveDirectionHeader.insert(waveDirectionHeader.end(),
                               waveDirectionHeader.begin() + 1,
                               waveDirectionHeader.end() - 1);
    std::reverse(waveDirectionHeader.begin() + center,
                 waveDirectionHeader.end());
    std::transform(waveDirectionHeader.begin() + center,
                   waveDirectionHeader.end(),
                   waveDirectionHeader.begin() + center,
                   [=](double x) {return 360.0 - x;});

    for (auto& row : waveHeightData) {
        row.insert(row.end(),
                   row.begin()+1,
                   row.end()-1);
        std::reverse(row.begin()+center,
                     row.end());
    }
}
/* ---------------------------------------------------------- */
void WaveData::printTable() {
    int width = 7;
    fmt::print("\n");
    fmt::print("{}", fmt::format("{:<{}}", "", width));
    fmt::print("{}", fmt::format("{:<{}.4g}", fmt::join(waveDirectionHeader, ""), width));
    fmt::print("\n\n");
    for (int i=0; i < wavePeriodHeader.size(); ++i){
        fmt::print("{}", fmt::format("{:<{}.4g}", wavePeriodHeader[i], width));
        fmt::print("{}", fmt::format("{:<{}.3f}", fmt::join(waveHeightData[i], ""), width));
        fmt::print("\n");
    }
}




