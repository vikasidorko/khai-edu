#include <iostream>
using namespace std;

int main()
{
    double d1, d2, S;

    cout << "Enter diagonal d1: ";
    cin >> d1;

    cout << "Enter diagonal d2: ";
    cin >> d2;

    S = (d1 * d2) / 2;

    cout << "Area of the rhombus: " << S << endl;


    double a, b, c, A;

    cout << "\nEnter number a: ";
    cin >> a;

    cout << "Enter number b: ";
    cin >> b;

    cout << "Enter number c: ";
    cin >> c;

    A = (a + b + c) / 3;

    cout << "Arithmetic mean: " << A << endl;


    double km, m, cm;

    cout << "\nEnter distance in kilometers: ";
    cin >> km;

    m = km * 1000;
    cm = km * 100000;

    cout << "Distance in meters: " << m << endl;
    cout << "Distance in centimeters: " << cm << endl;

    return 0;
}
