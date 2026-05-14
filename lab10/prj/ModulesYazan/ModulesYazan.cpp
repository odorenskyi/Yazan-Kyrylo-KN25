#include <cmath>
#include <string>
#include "ModulesYazan.h"
#define _USE_MATH_DEFINES // Для використання M_PI
#include <iostream>
#include <fstream>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <cctype>
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
// Допоміжна функція для Задачі 10.1 (має бути оголошена ДО task10_1)
bool hasExactWord(const string& text, const string& target) {
    size_t pos = text.find(target);
    while (pos != string::npos) {
        bool startMatch = (pos == 0 || isspace(text[pos - 1]) || ispunct(text[pos - 1]));
        bool endMatch = (pos + target.length() == text.length() || isspace(text[pos + target.length()]) || ispunct(text[pos + target.length()]));
        if (startMatch && endMatch) return true;
        pos = text.find(target, pos + 1);
    }
    return false;
}
void task10_1(const string& inputPath, const string& outputPath) {
    ifstream inFile(inputPath);
    if (!inFile.is_open()) return;

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    int charCount = content.length();
    inFile.close();

    ofstream outFile(outputPath, ios::trunc); // Перезапис файлу
    if (!outFile.is_open()) return;

    outFile << "Розробник: Язан, ЦНТУ, м. Кропивницький, Україна, 2026 р." << endl;
    outFile << "У файлі " << inputPath << " міститься " << charCount << " символів." << endl;

    string targets[] = {"програма", "модуль", "студент", "програміст"};
    for (const string& word : targets) {
        if (hasExactWord(content, word)) {
            outFile << "Слово \"" << word << "\" присутнє у тексті." << endl;
        } else {
            outFile << "Слово \"" << word << "\" відсутнє." << endl;
        }
    }
    outFile.close();
}

void task10_2(const string& inputPath) {
    ofstream inFile(inputPath, ios::app); // Дозапис
    if (!inFile.is_open()) return;

    inFile << "\nДержавні символи України: Державний Прапор України, Державний Герб України і Державний Гімн України." << endl;

    time_t now = time(0);
    char* dt = ctime(&now);
    inFile << "Дата запису: " << dt;
    inFile.close();
}

void task10_3(const string& outputPath, double x, double y, double z, unsigned int b) {
    ofstream outFile(outputPath, ios::app);
    if (!outFile.is_open()) return;

    double result = s_calculation(x, y, z);
    outFile << "Результат s_calculation(x,y,z): " << result << endl;

    string binary = bitset<16>(b).to_string();
    binary.erase(0, min(binary.find_first_not_of('0'), binary.size() - 1));
    outFile << "Число " << b << " у двійковому коді: " << binary << endl;

    outFile.close();
}
