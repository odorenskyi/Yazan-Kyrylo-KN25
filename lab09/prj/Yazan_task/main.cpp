#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "ModulesYazan.h"

using namespace std;

int main() {
    char ch;

    do {
        cout << "Введіть команду (5,4,3,7): ";
        cin >> ch;

        if (ch == '5') {
            double v;
            cout << "Швидкість вітру: ";
            cin >> v;

            int b;
            string desc;
            windInfo(v, b, desc);

            cout << "Бофорт: " << b << " | " << desc << endl;
        }
        else if (ch == '4') {
            int n;
            cout << "К-сть днів: ";
            cin >> n;

            double arr[100];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            double avgC = avgTempC(arr, n);
            double avgF = toFahrenheit(avgC);

            cout << "Середня (C): " << avgC << endl;
            cout << "Середня (F): " << avgF << endl;
        }
        else if (ch == '3') {
            unsigned int N;
            cout << "Введіть число: ";
            cin >> N;

            cout << "Результат: " << bitTask(N) << endl;
        }
        else if (ch == '7') {
            cout << "s_calculation()" << endl;
        }
        else {
            cout << "Помилка!" << '\a' << endl;
        }

        cout << "Вийти? (t/T/y): ";
        cin >> ch;

    } while (ch != 't' && ch != 'T' && ch != 'y');

    return 0;
}
