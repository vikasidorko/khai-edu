#include <iostream>
#include <cmath>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Оголошення функцій до main() з коментарями (ЛР №4, варіант 19)
// У тілі і при виклику функцій Завдання 1 цикли не використовуються.

void AddLeftDigit(int D, int& K); // Proc9: додає цифру D (1..9) зліва до цілого додатного числа K (0 < K < 1000)
bool CircleIntersect(double x1, double y1, double R1,
                     double x2, double y2, double R2); // Proc46: перевіряє перетин двох кіл (true/false)
void checkCirclePair(int pairIndex); // допоміжна функція для перевірки однієї пари кіл без використання циклу

bool in_Int6(int& pN);            // Завдання 2 (пп.1): введення двозначного числа (Integer6) з перевіркою
void calc_Int6(int pN, int& tens, int& ones); // Завдання 2 (пп.2): обчислення десятків та одиниць числа
void out_Int6(int pN, int tens, int ones);    // Завдання 2 (пп.3): виведення результату у консоль

void task_proc9();                // Процедура виконання Завдання 1.1 (Proc9)
void task_proc46();               // Процедура виконання Завдання 1.2 (Proc46)
void task_int6();                 // Процедура виконання Завдання 2 (Integer6)

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int menu; // вибір пункту меню
    cout << "Лабораторна робота №4 (Варіант 19)" << endl;
    cout << "1 - Завдання 1.1 (Proc9: додавання цифри зліва)" << endl;
    cout << "2 - Завдання 1.2 (Proc46: перевірка перетину трьох пар кіл)" << endl;
    cout << "3 - Завдання 2 (Integer6: десятки та одиниці двозначного числа)" << endl;
    cout << "Оберіть завдання (1-3): ";

    cin >> menu;
    if (cin.fail()) // перевірка коректності введення номера меню
    {
        cout << "Помилка: номер пункту меню має бути цілим числом!" << endl;
        return 1;
    }

    // Меню з використанням інструкції вибору switch (без циклів)
    switch (menu)
    {
        case 1:
            task_proc9();
            break;
        case 2:
            task_proc46();
            break;
        case 3:
            task_int6();
            break;
        default:
            cout << "Помилка: невідомий пункт меню! Введіть 1, 2 або 3." << endl;
            break;
    }

    return 0;
}

// Proc9. Додає до цілого додатного числа K цифру D зліва без використання циклів.
void AddLeftDigit(int D, int& K)
{
    if (K < 10)
        K += D * 10;      // 1-розрядне число -> додаємо в розряд десятків
    else if (K < 100)
        K += D * 100;     // 2-розрядне число -> додаємо в розряд сотень
    else if (K < 1000)
        K += D * 1000;    // 3-розрядне число -> додаємо в розряд тисяч
    else if (K < 10000)
        K += D * 10000;   // після першого додавання 3-розрядне K стає 4-розрядним
    else
        K += D * 100000;  // резервна гілка для 5-розрядного K
}

// Завдання 1.1: послідовно додати до K зліва цифри D1 та D2
void task_proc9()
{
    int K, D1, D2;
    cout << endl << "=== Завдання 1.1: Proc9 ===" << endl;
    cout << "Введіть ціле число K (0 < K < 1000): ";
    cin >> K;
    if (cin.fail() || K <= 0 || K >= 1000)
    {
        cout << "Помилка: число K має бути цілим в інтервалі (0; 1000)!" << endl;
        return;
    }

    cout << "Введіть дві цифри D1 та D2 (кожна в діапазоні 1..9): ";
    cin >> D1 >> D2;
    if (cin.fail() || D1 < 1 || D1 > 9 || D2 < 1 || D2 > 9)
    {
        cout << "Помилка: цифри D1 та D2 повинні належати діапазону [1; 9]!" << endl;
        return;
    }

    // Послідовний виклик процедури AddLeftDigit для D1 і D2
    AddLeftDigit(D1, K);
    cout << "Після додавання D1 зліва: K = " << K << endl;

    AddLeftDigit(D2, K);
    cout << "Після додавання D2 зліва: K = " << K << endl;
}

// Proc46. Повертає true, якщо два кола перетинаються (або дотикаються), і false в іншому випадку.
bool CircleIntersect(double x1, double y1, double R1,
                     double x2, double y2, double R2)
{
    // Відстань між центрами двох кіл
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    // Умова перетину або дотику: |R1 - R2| <= d <= R1 + R2
    return (fabs(R1 - R2) <= d && d <= R1 + R2);
}

// Допоміжна процедура для введення та перевірки однієї пари кіл (викликається тричі без циклу)
void checkCirclePair(int pairIndex)
{
    double x1, y1, R1, x2, y2, R2;
    cout << endl << "Пара кіл №" << pairIndex << ". Введіть x1 y1 R1 x2 y2 R2 (координати в [-100; 100], R > 0): ";
    cin >> x1 >> y1 >> R1 >> x2 >> y2 >> R2;

    if (cin.fail() ||
        x1 < -100.0 || x1 > 100.0 || y1 < -100.0 || y1 > 100.0 ||
        x2 < -100.0 || x2 > 100.0 || y2 < -100.0 || y2 > 100.0 ||
        R1 <= 0.0 || R1 > 100.0 || R2 <= 0.0 || R2 > 100.0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Помилка: перевірте діапазон координат [-100; 100] і радіусів (0; 100]!" << endl;
        return;
    }

    bool res = CircleIntersect(x1, y1, R1, x2, y2, R2);
    cout << "Кола пари №" << pairIndex << " перетинаються: " << boolalpha << res << endl;
}

// Завдання 1.2: перевірка перетину трьох пар кіл без використання циклів
void task_proc46()
{
    cout << endl << "=== Завдання 1.2: Proc46 ===" << endl;
    checkCirclePair(1);
    checkCirclePair(2);
    checkCirclePair(3);
}

// Завдання 2 (Integer6), пп.1: введення двозначного числа з перевіркою коректності
bool in_Int6(int& pN)
{
    cout << endl << "=== Завдання 2: Integer6 ===" << endl;
    cout << "Введіть ціле додатне двозначне число (10..99): ";
    cin >> pN;

    // Якщо сталася помилка потоку або число не належить [10; 99], повертаємо false
    if (cin.fail() || pN < 10 || pN > 99)
        return false;

    return true;
}

// Завдання 2 (Integer6), пп.2: обчислення лівої (десятки) та правої (одиниці) цифр числа
void calc_Int6(int pN, int& tens, int& ones)
{
    tens = pN / 10; // цілочисельне ділення дає цифру десятків
    ones = pN % 10; // залишок від ділення дає цифру одиниць
}

// Завдання 2 (Integer6), пп.3: виведення результатів у консоль
void out_Int6(int pN, int tens, int ones)
{
    cout << "Число: " << pN << endl;
    cout << "Ліва цифра (десятки): " << tens << endl;
    cout << "Права цифра (одиниці): " << ones << endl;
}

// Завдання 2 цілком
void task_int6()
{
    int n;
    if (!in_Int6(n))
    {
        cout << "Помилка: потрібно ввести ціле двозначне число від 10 до 99!" << endl;
        return; // при некоректних даних розрахунки не виконуються
    }

    int tens = 0, ones = 0;
    calc_Int6(n, tens, ones);
    out_Int6(n, tens, ones);
}
