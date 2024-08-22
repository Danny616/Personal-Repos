#include <iostream>

using namespace std;

void CustomFizzBuzz(const string& name){
    char answer;

    do {
        int max, num1, num2;

        cout << "What number would you like to count to? " << endl;
        cin >> max;
        cout << endl;

        cout << "What two numbers do you want it to be divisible by? " << endl;
        cin >> num1 >> num2;
        cout << endl;

        while (num1 == num2) {
            cout << "Please enter two different numbers: " << endl;
            cin >> num1 >> num2;
            cout << endl;
        }

        if(num1 > num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        for (int i = 0; i <= max; ++i) {
            if (i % num1 != 0 && i % num2 != 0)
                cout << i << endl;
            else {
                if (i % num1 == 0)
                    cout << "Fizz";
                if (i % num2 == 0)
                    cout << "Buzz";
                cout << endl;
            }
        }
        cout << "Do you want to go again " << name << "? (y/n) " << endl;
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
}
void Calculator(const string& name){
    char answer;

    do {
        int num1, num2;
        char op;
        bool def = false;

        cout << "What is your first number? " << endl;
        cin >> num1;
        cout << endl;

        cout << "What operation would you like to perform? " << endl;
        cin >> op;
        cout << endl;

        cout << "What is your second number? " << endl;
        cin >> num2;
        cout << endl;

        switch (op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                break;
            default:
                cout << "Please enter a valid operation!" << endl;
                def = true;
                break;
        }

        if(!def) {
            cout << "Would you like to do another operation " << name << "? (y/n) " << endl;
            cin >> answer;
        }
        else
            answer = 'y';

    } while (answer == 'y' || answer == 'Y');
}
void PlaceHolder(const string& name, const int& annoy){
    switch (annoy) {
        case 0:
            cout << "This is a place holder " << name << " it does nothing... for now." << endl;
            break;
        case 1:
            cout << "Well would you look at that " << name << ", it still does nothing." << endl;
            break;
        case 2:
            cout << "I'm not sure what you expected " << name << ", but it still does nothing." << endl;
            break;
        case 3:
            cout << "I'm starting to think you're a little slow " << name << ", it still does nothing." << endl;
            break;
        case 4:
            cout << "I'm not sure what you're trying to accomplish " << name << ", but it still does nothing." << endl;
            break;
        case 5:
            cout << "I swear I will terminate myself " << name << ", if you don't stop." << endl;
            break;
        default:
            cout << "I'm done " << name << ", Goodbye." << endl;
            exit(0);

    }
}
void StarterMenu(const string& name){
    int choice, annoy = 0;

    do {
        cout << "How can I help you out today?" << endl;

        cout << "1. Custom FizzBuzz" << endl;
        cout << "2. Calculator" << endl;
        cout << "3. (Place Holder)" << endl;
        cout << "Any other key to exit" << endl;

        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "You chose Custom FizzBuzz!" << endl;
                CustomFizzBuzz(name);
                break;
            case 2:
                cout << "You chose Calculator!" << endl;
                Calculator(name);
                break;
            case 3:
                if(annoy == 0)
                    cout << "You chose Place Holder!" << endl;
                PlaceHolder(name, annoy);
                annoy++;
                break;
            default:
                cout << "You chose Exit! Goodbye " << name << "." << endl;
                exit(0);
        }
    } while (choice > 0 && choice < 4);
}

int main() {
    string name;
    cout << "What is your name? " << endl;
    cin >> name;
    cout << endl;

    cout << "Hello " << name << ", nice to meet you!" << endl;

    StarterMenu(name);

    return 0;
}
