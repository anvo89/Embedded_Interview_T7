#include <iostream>

using namespace std;

enum class Direction {
    CLOCKWISE,
    COUNTERCLOCKWISE
};

class DCMotor {
private:
    double voltage;
    double maxCurrent;
    double speed;
    Direction direction;
    bool running;

public:
    DCMotor(double voltage, double maxCurrent, double speed);
    void setSpeed(double speed);
    void setDirection(Direction direction);
    void start();
    void stop();
    bool isRunning();
};

DCMotor::DCMotor(double voltage, double maxCurrent, double speed) {
    this->voltage = voltage;
    this->maxCurrent = maxCurrent;
    this->speed = speed;
    this->direction = Direction::CLOCKWISE;
    this->running = false;
}

void DCMotor::setSpeed(double speed) {
    this->speed = speed;
}

void DCMotor::setDirection(Direction direction) {
    this->direction = direction;
}

void DCMotor::start() {
    if (!running) {
        running = true;
        cout << "Motor started." << endl;
    }
}

void DCMotor::stop() {
    if (running) {
        running = false;
        cout << "Motor stopped." << endl;
    }
}

bool DCMotor::isRunning() {
    return running;
}

class FeedbackSystem {
private:
    DCMotor& dcMotor;

public:
    FeedbackSystem(DCMotor& motor) : dcMotor(motor) {}
    
    void checkOverload(double current, double maxCurrent);
    void checkOverheat(double temperature);
    void controllMotor(double current, double maxCurrent, double temperature);
};

void FeedbackSystem::checkOverload(double current, double maxCurrent) {
    if (current > maxCurrent) {
        cout << "Overload detected. Stopping motor." << endl;
        dcMotor.stop();
    }
}

void FeedbackSystem::checkOverheat(double temperature) {
    if (temperature > 80.0) {
        cout << "Overheat detected. Stopping motor." << endl;
        dcMotor.stop();
    }
}

void FeedbackSystem::controllMotor(double current, double maxCurrent, double temperature) {
    dcMotor.start();
    dcMotor.setDirection(Direction::CLOCKWISE); 
    dcMotor.setSpeed(2000.0); 

    checkOverload(current, maxCurrent);
    checkOverheat(temperature);
}

int main() {
    DCMotor dcMotor(13.0, 1.5, 0.0); 
    FeedbackSystem feedback(dcMotor);

    feedback.controllMotor(12.0, 1.4, 90.0); 
    return 0;
}
