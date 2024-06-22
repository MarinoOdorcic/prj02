#include "WaveData.h"

/* ---------------------------------------------------------- */
void WaveData::loadFullData() {
    waveDirectionHeading = {0.000, 10.000, 45.000, 90.000, 135.000, 180.000, 225.000, 270.000, 315.000};
    wavePeriodHeading = {0.000, 2.000, 3.000, 4.000, 6.000, 8.000, 10.000, 12.000};
    waveHeightData = {
            {1.000, 1.0222222, 1.100, 1.200, 1.300, 1.400, 1.500, 1.600, 1.700},
            {2.000, 2.0222222, 2.100, 2.200, 2.300, 2.400, 2.500, 2.600, 2.700},
            {3.000, 3.0222222, 3.100, 3.200, 3.300, 3.400, 3.500, 3.600, 3.700},
            {4.000, 4.0222222, 4.100, 4.200, 4.300, 4.400, 4.500, 4.600, 4.700},
            {6.000, 6.0222222, 6.100, 6.200, 6.300, 6.400, 6.500, 6.600, 6.700},
            {8.000, 8.0222222, 8.100, 8.200, 8.300, 8.400, 8.500, 8.600, 8.700},
            {10.000, 10.0222222, 10.100, 10.200, 10.300, 10.400, 10.500, 10.600, 10.700},
            {12.000, 12.0222222, 12.100, 12.200, 12.300, 12.400, 12.500, 12.600, 12.700}
    };
}
/* ---------------------------------------------------------- */
void WaveData::loadSymmetricData() {
    waveDirectionHeading = {0.000, 22.500, 45.000, 67.500, 90.000, 112.500, 135.000, 157.500, 180.000};
    wavePeriodHeading = {7.000, 8.000, 9.000, 10.000, 12.000, 14.000};
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
    waveDirectionHeading = {1,2,3,4,5};
    wavePeriodHeading = {1,2,3,4,5};
    waveHeightData = {
            {1,2,3,4,5},
            {5,6,7,8,9},
            {9,10,11,12,13},
            {13,14,15,16,17},
            {17,18,19,20,21}
    };
}
/* ---------------------------------------------------------- */
void WaveData::mirrorExtendData() {
    int center = static_cast<int>(waveDirectionHeading.size());

    waveDirectionHeading.insert(waveDirectionHeading.end(),
                                waveDirectionHeading.begin()+1,
                                waveDirectionHeading.end()-1);
    std::reverse(waveDirectionHeading.begin()+center,
                 waveDirectionHeading.end());
    std::transform(waveDirectionHeading.begin()+center,
                   waveDirectionHeading.end(),
                   waveDirectionHeading.begin()+center,
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
    fmt::print("{}", fmt::format("{:<{}.4g}", fmt::join(waveDirectionHeading, ""), width));
    fmt::print("\n\n");
    for (int i=0; i<wavePeriodHeading.size(); ++i){
        fmt::print("{}", fmt::format("{:<{}.4g}", wavePeriodHeading[i], width));
        fmt::print("{}", fmt::format("{:<{}.3f}", fmt::join(waveHeightData[i], ""), width));
        fmt::print("\n");
    }
}
