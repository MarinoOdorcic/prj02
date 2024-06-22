#ifndef PRJ02_SHIPDATA_H
#define PRJ02_SHIPDATA_H



class ShipData {
private:
    double shipDirection;
    double shipHeight;
public:
    /* ----- Constructors --------------------------------------- */
    ShipData(double angle, double height);
    /* ----- Get Variable --------------------------------------- */
    double getDirection() const;
    double getHeight() const;
};

#endif //PRJ02_SHIPDATA_H
