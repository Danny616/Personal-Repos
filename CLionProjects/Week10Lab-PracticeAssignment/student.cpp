#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll_no;

public:
    void setName(string stuname);
    string getName() const;
    void setRoll(int roll);
    int getRoll() const;
};

void Student::setName(string stuname) {
    name = stuname;
}

string Student::getName() const {
    return name;
}

void Student::setRoll(int roll) {
    roll_no = roll;
}

int Student::getRoll() const {
    return roll_no;
}

int main() {
    Student stud3;

    stud3.setName("Jerry");
    stud3.setRoll(3);

    cout << stud3.getName() << " " << stud3.getRoll() << endl;

    return 0;
}