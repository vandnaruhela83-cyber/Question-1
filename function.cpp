#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    cout << calc.add(2, 3) << endl;        // calls add(int, int)       -> 5
    cout << calc.add(2.5, 3.5) << endl;    // calls add(double, double) -> 6
    cout << calc.add(1, 2, 3) << endl;     // calls add(int, int, int)  -> 6
    return 0;
}
