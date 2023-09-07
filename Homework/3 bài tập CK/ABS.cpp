/*
*File: ABS.cpp
*Author: Vo Thi Ngoc An
*Date: 7/9/2023
*Description: 
*/

#include <iostream>

using namespace std;

class Wheel{
    private:
        double SPEED;
    public:
    Wheel::Wheel(double speed);
    void setSpeed(double speed);
    double getSpeed();
};
Wheel::Wheel(double speed){
    this->SPEED=speed;
};
void Wheel::setSpeed(double speed){
    SPEED=speed;
};
double Wheel::getSpeed(){
    return SPEED;
}

class Car{
    private:
        const double initial_weight = 1000;
        double car_weight;
        vector<double>passenger_weights;
    public:
        Car::Car(double Carweight);
        void setCar_weight(double Carweight);
        double getCar_weight();
        void addPassengerWeight(double passengerWeight);
        double getTotalWeight();

};
Car::Car(double Carweight){
    this->car_weight=Carweight;
};
void Car::setCar_weight(double Carweight){
    car_weight=Carweight;
};
double Car::getCar_weight(){
    return Carweight;
}
void Car::addPassengerWeight(double passengerWeight){
    passenger_weights.push_back(passengerWeight);
}
double Car::getTotalWeight(){
    double totalWeight=car_weight;
    // for-each
    for (double& passengerWeight:passener_weights){
        totalWeight+=passengerWeight;
    }
    return totalWeight;
}

class ABS{
    private:
    const double min_speed_threshold = 10;
    Car* car;   // trỏ đến class Car
    Wheel* wheel;  // trỏ đến lớp Wheel

    public:
    ABS::ABS(Car* car,Wheel* wheel);
    void applyBrakes(double carWeight,double wheelSpeed);
}

ABS::ABS(Car* car,Wheel* wheel){
    this->car=carWeight;
    this->wheel=wheelSpeed;
}
void applyBrakes(){
    double carWeight = car->getTotalWeight();
    double wheelSpeed = wheel->getSpeed();

 if (wheelSpeed < min_speed_threshold) {
            cout << "Cảnh báo: Bánh xe có nguy cơ bị bó cứng!" << endl;
            // Điều chỉnh lực phanh dựa trên khối lượng của xe ở đây
            double adjustedBrakeForce = calculateAdjustedBrakeForce(carWeight);
            // Áp dụng lực phanh điều chỉnh
            car->applyBrake(adjustedBrakeForce);
        } else {
            // Áp dụng phanh bình thường
            car->applyBrake();
        }}


int main(){
    
}