#include <iostream>

using namespace std;

int main()
{
    // --- Завдання 1. Обчислення площі ромба за двома діагоналями ---
    // декларація змінних
    double d1, d2, S;

    // введення змінних (діагоналей)
    cout << "Enter diagonal d1: ";
    cin >> d1;

    cout << "Enter diagonal d2: ";
    cin >> d2;

    // розрахунок результату
    S = (d1 * d2) / 2;

    // вивід результату
    cout << "Area of the rhombus: " << S << endl;


    // --- Завдання 2. Знаходження середнього арифметичного трьох чисел ---
    // декларація змінних
    double a, b, c, A;

    // введення змінних
    cout << "\nEnter number a: ";
    cin >> a;

    cout << "Enter number b: ";
    cin >> b;

    cout << "Enter number c: ";
    cin >> c;

    // розрахунок результату
    A = (a + b + c) / 3;

    // вивід результату
    cout << "Arithmetic mean: " << A << endl;


    // --- Завдання 3. Переведення кілометрів у метри та сантиметри ---
    // декларація змінних
    double km, m, cm;

    // введення змінної
    cout << "\nEnter distance in kilometers: ";
    cin >> km;

    // розрахунок результату
    m = km * 1000;
    cm = km * 100000;

    // вивід результату
    cout << "Distance in meters: " << m << endl;
    cout << "Distance in centimeters: " << cm << endl;

    // завершення програми
    return 0;
}
