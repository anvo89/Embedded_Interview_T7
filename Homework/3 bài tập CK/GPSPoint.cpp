/*
*File:GPSPoint.cpp
*Author: Vo Thi Ngoc An
*Date: 6/9/2023
*Description: Calculating the distance between 2 points on the Earth.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double EARTH_RADIUS = 6371.0; 
// Bán kính trung bình của trái đất (km)

class GPSPoint {
private:
    double latitude;
    double longitude;

public:
    void input();
    bool isValid();
    double toRadians(double degrees);
    double distanceTo(const GPSPoint& otherPoint);
};

void GPSPoint::input() {
    cout << "Nhập vĩ độ (latitude) của điểm GPS: ";
    cin >> latitude;

    while (!isValid()) {
        cout << "Vĩ độ không hợp lệ. Vĩ độ phải nằm trong khoảng [-90, 90]. Nhập lại: ";
        cin >> latitude;
    }

    cout << "Nhập kinh độ (longitude) của điểm GPS: ";
    cin >> longitude;

    while (!isValid()) {
        cout << "Kinh độ không hợp lệ. Kinh độ phải nằm trong khoảng [-180, 180]. Nhập lại: ";
        cin >> longitude;
    }
}

bool GPSPoint::isValid() {
    return (latitude >= -90.0 && latitude <= 90.0) && (longitude >= -180.0 && longitude <= 180.0);
}

double GPSPoint::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double GPSPoint::distanceTo(const GPSPoint& otherPoint) {
    double lat1 = toRadians(latitude);
    double lon1 = toRadians(longitude);
    double lat2 = toRadians(otherPoint.latitude);
    double lon2 = toRadians(otherPoint.longitude);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

int main() {
    GPSPoint point1, point2;

    cout << "Nhập tọa độ cho điểm thứ nhất:\n";
    point1.input();

    cout << "Nhập tọa độ cho điểm thứ hai:\n";
    point2.input();

    double distance = point1.distanceTo(point2);

    cout << "Khoảng cách giữa hai điểm trên trái đất là: " << distance << " km" << endl;

    return 0;
}
