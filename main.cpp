#include <iostream>
#include <cmath>
using namespace std;

/* ============================================================
   ФУНКЦІЇ ВВЕДЕННЯ З КОНСОЛІ
   ============================================================ */

// Введення цілого числа
int inputInt(const string& msg) 
{
    int x;
    cout << msg;
    cin >> x;
    return x;
}

// Введення дійсного числа
double inputDouble(const string& msg) 
{
    double x;
    cout << msg;
    cin >> x;
    return x;
}

/* ============================================================
   ЗАВДАННЯ 1
   Варіант 13 — права нижня чверть кола радіуса r
   x >= 0, y <= 0, x^2 + y^2 <= r^2
   ============================================================ */

bool inFigure13(double x, double y, double r) 
{
    return (x >= 0 && y <= 0 && x * x + y * y <= r * r);
}

void task1() 
{
    int n = inputInt("Введіть кількість точок n: ");
    double r = inputDouble("Введіть радіус r: ");

    int count = 0;

    for (int i = 1; i <= n; i++) 
    {
        double x = inputDouble("x = ");
        double y = inputDouble("y = ");

        if (inFigure13(x, y, r))
            count++;
    }

    cout << "Кількість точок у фігурі: " << count << endl;
}

/* ============================================================
   ЗАВДАННЯ 2
   S = Σ x^(i+2) / (5^i + i), |x| < 4
   Вивести кожен третій елемент
   ============================================================ */

double calcSeries(double x, int n) 
{
    double S = 0;
    for (int i = 0; i <= n; i++) 
    {
        S += pow(x, i + 2) / (pow(5, i) + i);
    }
    return S;
}

void task2() 
{
    double x = inputDouble("Введіть x (|x| < 4): ");
    if (fabs(x) >= 4) 
    {
        cout << "Помилка: |x| >= 4\n";
        return;
    }

    int n = inputInt("Введіть n: ");

    cout << "Значення суми S = " << calcSeries(x, n) << endl;

    cout << "Кожен третій елемент:\n";
    for (int i = 0; i <= n; i += 3) 
    {
        double value = pow(x, i + 2) / (pow(5, i) + i);
        cout << "i = " << i << " -> " << value << endl;
    }
}

/* ============================================================
   ЗАВДАННЯ 3
   Σ (n^3 + 3^n) / (2n + 1)!
   ============================================================ */

long double factorial(int n) 
{
    long double f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

void task3() 
{
    const double eps = 1e-5;
    const double g = 1e3;

    long double sum = 0;
    int n = 1;

    while (true) 
    {
        long double un =
            (pow(n, 3) + pow(3, n)) / factorial(2 * n + 1);

        if (fabsl(un) < eps) 
        {
            cout << "Ряд збіжний\n";
            break;
        }

        if (fabsl(un) > g) 
        {
            cout << "Ряд розбіжний\n";
            break;
        }

        sum += un;
        n++;
    }

    cout << "Сума ряду = " << sum << endl;
}

/* ============================================================
   ЗАВДАННЯ 4 — МЕНЮ
   ============================================================ */

int main() 
{
    int choice;

    do 
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 – Завдання 1 (Точки, варіант 13)\n";
        cout << "2 – Завдання 2 (Сума)\n";
        cout << "3 – Завдання 3 (Ряд)\n";
        cout << "0 – Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Завершення програми...\n"; break;
        default: cout << "Невірний вибір\n";
        }
    } 
    while (choice != 0);

    return 0;
}
