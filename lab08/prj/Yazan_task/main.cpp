#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "ModulesYazan.h"

using namespace std;

void show_copyright() {
    cout << "Розробник: Yazan Kirill ©" << endl;
}

bool check_expression(int a, int b) {
    return (a + 5) >= b;
}

void show_results(double x, double y, double z) {
    double s = s_calculation(x, y, z);

    cout << "Десятковий вигляд: " << fixed << setprecision(2)
         << "x=" << x << ", y=" << y << ", z=" << z << endl;

    cout << "Шістнадцятковий вигляд: "
         << "x=" << hex << (int)x << ", "
         << "y=" << hex << (int)y << ", "
         << "z=" << hex << (int)z << dec << endl;

    cout << "Результат S: " << setprecision(4) << s << endl;
}

int main() {
    double x, y, z;
    int a, b;

    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть цілі числа a та b: ";
    cin >> a >> b;

    show_copyright();
    cout << "Результат виразу a + 5 >= b: " << boolalpha << check_expression(a, b) << endl;
    show_results(x, y, z);

    return 0;
}
