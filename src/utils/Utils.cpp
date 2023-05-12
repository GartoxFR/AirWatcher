#include <math.h>

const double EARTH_RADIUS = 6371.009;

double CalculDistance(double latitude1, double longitude1, double latitude2,
                      double longitude2) {
    // Conversion to rad
    latitude1 = latitude1 * (M_PI / 180);
    latitude2 = latitude2 * (M_PI / 180);
    longitude1 = longitude1 * (M_PI / 180);
    longitude2 = longitude2 * (M_PI / 180);

    double haversine = (pow(sin((1.0 / 2) * (latitude2 - latitude1)), 2)) +
                       ((cos(latitude1)) * (cos(latitude2)) *
                        (pow(sin((1.0 / 2) * (longitude2 - longitude1)), 2)));

    double d = EARTH_RADIUS * 2 * asin(fmin(1.0, sqrt(haversine)));
    return d;
}
