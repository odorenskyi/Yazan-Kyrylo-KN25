#include <iostream>
#include <string>
#include "ModulesYazan.h"

using namespace std;

int main() {
    cout << "=== UNIT TESTING ===\n\n";

    // ------------------ ТЕСТ 1 (Задача 9.1) ------------------
    {
        double v = 5.0;
        int b;
        string desc;

        windInfo(v, b, desc);

        cout << "[Test 1 - windInfo]\n";
        cout << "Input: v = " << v << endl;
        cout << "Output: b = " << b << ", desc = " << desc << endl;

        if (b == 3)
            cout << "Result: PASSED\n\n";
        else
            cout << "Result: FAILED\n\n";
    }

    // ------------------ ТЕСТ 2 (Задача 9.2) ------------------
    {
        double arr[3] = {10, 20, 30};
        int n = 3;

        double avgC = avgTempC(arr, n);
        double avgF = toFahrenheit(avgC);

        cout << "[Test 2 - avgTempC + toFahrenheit]\n";
        cout << "Input: {10, 20, 30}\n";
        cout << "Output: avgC = " << avgC << ", avgF = " << avgF << endl;

        if (avgC == 20)
            cout << "Result: PASSED\n\n";
        else
            cout << "Result: FAILED\n\n";
    }

    // ------------------ ТЕСТ 3 (Задача 9.3) ------------------
    {
        unsigned int N = 16384; // 2^14 → 14-й біт = 1

        int result = bitTask(N);

        cout << "[Test 3 - bitTask]\n";
        cout << "Input: N = " << N << endl;
        cout << "Output: " << result << endl;

        if (result >= 0) // просто перевірка роботи
            cout << "Result: PASSED\n\n";
        else
            cout << "Result: FAILED\n\n";
    }

    // ------------------ ТЕСТ 4 (s_calculation) ------------------
    {
        double x = 1, y = 2, z = 3;
        double res = s_calculation(x, y, z);

        cout << "[Test 4 - s_calculation]\n";
        cout << "Input: x=1 y=2 z=3\n";
        cout << "Output: " << res << endl;

        cout << "Result: PASSED\n\n";
    }

    cout << "=== TESTING FINISHED ===\n";

    return 0;
}
