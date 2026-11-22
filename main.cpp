#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Оголошення функцій введення та процедур завдань (ЛР №5, варіант 19)
int readInt(const char* prompt, int minVal, int maxVal);         // безпечне введення цілого числа у заданих межах
double readDouble(const char* prompt, double minVal, double maxVal); // безпечне введення дійсного числа у заданих межах
void task1(); // Завдання 1 (Табл. 1 №14): підрахунок кількості точок у фігурі
void task2(); // Завдання 2 (Табл. 2 №7): обчислення суми ряду та виведення кожного 4-го елемента
void task3(); // Завдання 3 (Табл. 3 №30): дослідження ряду на збіжність/розбіжність

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int menu; // змінна для вибору пункту меню
    // Організація меню за допомогою циклу з післяумовою do-while та інструкції switch
    do
    {
        cout << endl << "=== Лабораторна робота №5 (Варіант 19) ===" << endl;
        cout << "1 - Завдання 1 (Табл. 1 №14: підрахунок точок у фігурі)" << endl;
        cout << "2 - Завдання 2 (Табл. 2 №7: обчислення суми ряду)" << endl;
        cout << "3 - Завдання 3 (Табл. 3 №30: збіжність/розбіжність ряду)" << endl;
        cout << "0 - Вихід з програми" << endl;
        cout << "Ваш вибір: ";
        cin >> menu;

        if (cin.fail()) // обробка нечислового введення для меню
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка: введіть ціле число (0..3)!" << endl;
            menu = -1;
            continue;
        }

        switch (menu)
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                cout << "Завершення роботи програми." << endl;
                break;
            default:
                cout << "Невірний пункт меню! Оберіть 0, 1, 2 або 3." << endl;
                break;
        }
    } while (menu != 0); // вихід із програми при виборі 0

    return 0;
}

// Функція безпечного введення цілого числа з перевіркою діапазону [minVal; maxVal]
int readInt(const char* prompt, int minVal, int maxVal)
{
    int value;
    while (true) // цикл з передумовою до отримання коректного значення
    {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= minVal && value <= maxVal)
            return value;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Помилка: введіть ціле число в межах [" << minVal << "; " << maxVal << "]!" << endl;
    }
}

// Функція безпечного введення дійсного числа з перевіркою діапазону [minVal; maxVal]
double readDouble(const char* prompt, double minVal, double maxVal)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= minVal && value <= maxVal)
            return value;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Помилка: введіть число в межах [" << minVal << "; " << maxVal << "]!" << endl;
    }
}

// Завдання 1 (Таблиця 1, №14).
// Чорна область №14 складається з:
// 1) сектора кола з центром (r, r) і радіусом r в I чверті: (x-r)^2 + (y-r)^2 <= r^2, y <= r, x + y >= 2r;
// 2) трикутника в IV чверті: x >= r, y <= 0, y >= x - 2r.
void task1()
{
    cout << endl << "--- Завдання 1 (Геометрична область №14) ---" << endl;
    double r = readDouble("Введіть радіус r (0 < r <= 100): ", 1e-6, 100.0);
    int n = readInt("Введіть кількість точок n (1..50): ", 1, 50);

    int insideCount = 0; // лічильник точок, що потрапили у фігуру
    for (int i = 1; i <= n; i++) // параметризований цикл для n точок
    {
        cout << "Точка " << i << ":" << endl;
        double x = readDouble("  x = ", -1000.0, 1000.0);
        double y = readDouble("  y = ", -1000.0, 1000.0);

        double dx = x - r;
        double dy = y - r;
        // Перевірка першої частини (сектор верхнього кола)
        bool inCircleWedge = (dx * dx + dy * dy <= r * r) && (y <= r) && (x + y >= 2.0 * r);
        // Перевірка другої частини (трикутник у IV чверті)
        bool inBottomTriangle = (x >= r) && (y <= 0.0) && (y >= x - 2.0 * r);

        if (inCircleWedge || inBottomTriangle)
        {
            insideCount++;
            cout << "  -> Точка (" << x << "; " << y << ") потрапляє у фігуру №14." << endl;
        }
        else
        {
            cout << "  -> Точка (" << x << "; " << y << ") не потрапляє у фігуру №14." << endl;
        }
    }

    cout << "Загальна кількість точок у фігурі №14: " << insideCount << " із " << n << "." << endl;
}

// Завдання 2 (Таблиця 2, №7).
// Обчислити S = sum_{k=0..n} (k*(k+1) - x^k) / x^(2k+1), 2 <= x <= 5.
// Варіант 19 (непарний): вивести значення кожного четвертого елемента.
void task2()
{
    cout << endl << "--- Завдання 2 (Табл. 2 №7, непарний варіант) ---" << endl;
    double x = readDouble("Введіть дійсне число x (2 <= x <= 5): ", 2.0, 5.0);
    int n = readInt("Введіть натуральне число n (1..100): ", 1, 100);

    double sum = 0.0;
    for (int k = 0; k <= n; k++) // цикл обчислення членів суми від k = 0 до n
    {
        double num = static_cast<double>(k) * (k + 1) - pow(x, k); // чисельник: k(k+1) - x^k
        double den = pow(x, 2 * k + 1);                           // знаменник: x^(2k+1)
        double term = num / den;
        sum += term;

        int order = k + 1; // порядковий номер елемента (1, 2, 3, 4, ...)
        if (order % 4 == 0)
        {
            cout << "Елемент #" << order << " (k=" << k << "): "
                 << fixed << setprecision(8) << term << endl;
        }
    }

    cout << "Сума ряду S = " << fixed << setprecision(8) << sum << endl;
}

// Завдання 3 (Таблиця 3, №30).
// Дослідити на збіжність ряд sum_{n=1..inf} (x^n * n!) / n^(n/2).
void task3()
{
    cout << endl << "--- Завдання 3 (Табл. 3 №30: дослідження ряду) ---" << endl;
    double x = readDouble("Введіть дійсне x (-100 <= x <= 100): ", -100.0, 100.0);
    double e = readDouble("Введіть малу межу e (1e-20 <= e <= 1e-2): ", 1e-20, 1e-2);
    double g = readDouble("Введіть велику межу g (1e2 <= g <= 1e5): ", 1e2, 1e5);
    int M = readInt("Введіть крок виведення M (1..20): ", 1, 20);

    int n = 1;
    double fact = 1.0;        // значення n!
    double x_pow = x;         // значення x^n
    double u = x_pow * fact / pow(static_cast<double>(n), n / 2.0); // перший член ряду (n=1)
    double sum = 0.0;

    cout << fixed << setprecision(15);
    while (fabs(u) >= e && fabs(u) <= g && n <= 200) // цикл з передумовою поки |u_n| в [e; g]
    {
        sum += u;
        if (n % M == 0)
        {
            cout << "n = " << setw(3) << n << " | u_n = " << u << " | S = " << sum << endl;
        }
        n++;
        fact *= n;
        x_pow *= x;
        u = x_pow * fact / pow(static_cast<double>(n), n / 2.0);
    }

    // Додавання та виведення граничного елемента, на якому спрацювала умова зупинки
    sum += u;
    cout << "Останній крок n = " << n << " | u_n = " << u << " | S = " << sum << endl;

    if (fabs(u) > g)
        cout << "Висновок: |u_n| > g (" << g << "), ряд РОЗБІЖНИЙ." << endl;
    else if (fabs(u) < e)
        cout << "Висновок: |u_n| < e (" << e << "), ряд ЗБІЖНИЙ (при x = 0 усі члени рівні 0)." << endl;
    else
        cout << "Висновок: досягнуто ліміт ітерацій." << endl;
}
