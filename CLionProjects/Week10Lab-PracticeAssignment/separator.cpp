#include <iostream>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    void setSides(double s1, double s2, double s3);
    double getArea() const;
    double getPerm() const;

};

double Triangle::getArea() const {
    return ((side1*side2)/2);
}

double Triangle::getPerm() const {
    return side1+side2+side3;
}

void Triangle::setSides(double s1, double s2, double s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

int main() {
    Triangle object1;

    object1.setSides(3,4,5);

    cout << object1.getArea() << endl;
    cout << "Perimeter is " << object1.getPerm() << endl;
    return 0;
}