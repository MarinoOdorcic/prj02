#include "ShipData.h"

/* ----- Constructors --------------------------------------- */
ShipData::ShipData(double angle, double height) {
    shipDirection = angle;
    shipHeight = height;
}

/* ----- Get Variable --------------------------------------- */
double ShipData::getDirection() const {
    return shipDirection;
}
/* ---------------------------------------------------------- */
double ShipData::getHeight() const {
    return shipHeight;
}
