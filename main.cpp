#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "fmt/core.h"

#include "ShipData.h"
#include "WaveData.h"
#include "InterpolationPolicies.h"
#include "Interpolator2D.h"

bool checkManeuver(ShipData shipData, WaveData waveData){
    bool shipManeuver;

    auto shipDirection = shipData.getDirection();
    auto shipHeight = shipData.getHeight();
    auto waveDirection = waveData.getDirection();
    auto wavePeriod = waveData.getPeriod();

    auto waveDirectionHeader = waveData.getDirectionHeader();
    auto wavePeriodHeader = waveData.getPeriodHeader();
    auto waveHeightData = waveData.getHeightData();

    double relativeDirection = waveDirection - shipDirection;

    Interpolator2D <LinearInterpolation,LinearInterpolation> interpolator;
    double waveHeight = interpolator.interpolate(wavePeriodHeader,
                                                 waveDirectionHeader,
                                                 waveHeightData,
                                                 relativeDirection,
                                                 wavePeriod);

    if (shipHeight > waveHeight){
        fmt::print("\n{}",std::string(40, '-'));
        fmt::print("\nShip maneuver safe");
        fmt::print("\n{}",std::string(40, '-'));
        return shipManeuver = true;
    } else {
        fmt::print("\n{}",std::string(40, '-'));
        fmt::print("\nShip maneuver NOT safe!!!");
        fmt::print("\n{}",std::string(40, '-'));
        return shipManeuver = false;
    }
}

int main() {

    ShipData shipData(0, 7.1);
    WaveData waveData(0, 12);

    waveData.loadTestData();
    waveData.loadFullData();
//    waveData.loadSymmetricData();
//    waveData.mirrorExtendData();
    waveData.printTable();

    bool shipManeuver = checkManeuver(shipData, waveData);

    return 0;
}