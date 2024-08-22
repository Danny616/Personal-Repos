#include <iostream>
using namespace std;

class Circle {
public:
    void setRadius(double num);
    double getRadius() const;
    double getArea() const;

private:
    double radius;
};

void Circle::setRadius(double num) {
    radius = num;
}

double Circle::getRadius() const {
    return radius;
}
double Circle::getArea() const {
    return 3.14159*radius*radius;
}

int main() {
    Circle num1;

    num1.setRadius(3);

    cout << "Circle with radius:" << num1.getRadius() << endl;
    cout << "Circle Area:" << num1.getArea() << endl;

    return 0;
}
