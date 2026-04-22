#include <cmath>
#include <string>
#include "D:\Yazan-Kyrylo-KN25\lab08\prj\ModulesYazan.h"
using namespace std;



double s_calculation(double x, double y, double z) {
    return M_PI * x + pow(exp(1.0), abs(y)) - sqrt(abs(pow(z, 2) - y));
}

void windInfo(double v, int &b, string &desc) {
    if (v < 0.3) { b = 0; desc = "Штиль"; }
    else if (v <= 1.5) { b = 1; desc = "Легкий вітер"; }
    else if (v <= 3.3) { b = 2; desc = "Слабкий вітер"; }
    else if (v <= 5.4) { b = 3; desc = "Легкий бриз"; }
    else if (v <= 7.9) { b = 4; desc = "Помірний вітер"; }
    else if (v <= 10.7) { b = 5; desc = "Свіжий вітер"; }
    else if (v <= 13.8) { b = 6; desc = "Сильний вітер"; }
    else if (v <= 17.1) { b = 7; desc = "Міцний вітер"; }
    else if (v <= 20.7) { b = 8; desc = "Шторм"; }
    else if (v <= 24.4) { b = 9; desc = "Сильний шторм"; }
    else if (v <= 28.4) { b = 10; desc = "Буря"; }
    else if (v <= 32.6) { b = 11; desc = "Жорстокий шторм"; }
    else { b = 12; desc = "Ураган"; }
}

double avgTempC(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

double toFahrenheit(double c) {
    return 32 + (9.0 / 5.0) * c;
}

int bitTask(unsigned int N) {
    int count0 = 0, count1 = 0;

    unsigned int temp = N;
    while (temp > 0) {
        if (temp & 1) count1++;
        else count0++;
        temp >>= 1;
    }

    // перевірка 14-го біта
    if (N & (1 << 14))
        return count0;
    else
        return count1;
}
