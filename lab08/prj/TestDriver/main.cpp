#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesYazan.h" // Підключаємо заголовок вашої бібліотеки

using namespace std;

int main() {
    // Налаштування виводу для консолі [cite: 37]
    cout << "=== Unit Testing: s_calculation ===" << endl;
    cout << "-----------------------------------" << endl;
    cout << setw(5) << "ID" << setw(10) << "x" << setw(10) << "y" << setw(10) << "z"
         << setw(15) << "Result" << setw(10) << "Status" << endl;
    cout << "-----------------------------------" << endl;

    // Структура для тестових даних
    struct TestCase {
        double x, y, z, expected;
    };

    // Приклади тест-кейсів (очікувані значення потрібно розрахувати на калькуляторі)
    TestCase tests[] = {
        {1.0, 0.0, 1.0, 4.1416},  // Тест 1
        {0.0, 2.0, 3.0, 4.7218},  // Тест 2
        {2.0, -1.0, 0.0, 8.0016}  // Тест 3
    };

    for (int i = 0; i < 3; i++) {
        double result = s_calculation(tests[i].x, tests[i].y, tests[i].z);

        // Виведення вхідних даних та результату [cite: 37]
        cout << setw(5) << i + 1
             << setw(10) << tests[i].x
             << setw(10) << tests[i].y
             << setw(10) << tests[i].z
             << setw(15) << fixed << setprecision(4) << result;

        // Перевірка статусу (passed/failed) [cite: 37]
        if (abs(result - tests[i].expected) < 0.001) {
            cout << setw(10) << "passed" << endl;
        } else {
            cout << setw(10) << "failed" << endl;
        }
    }

    cout << "-----------------------------------" << endl;
    return 0;
}
