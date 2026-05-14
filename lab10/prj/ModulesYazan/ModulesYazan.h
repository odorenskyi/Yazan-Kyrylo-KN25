#ifndef MODULES_H_INCLUDED
#define MODULES_H_INCLUDED
#include <string>

// --- Задача 9.1 ---
void windInfo(double v, int &b, std::string &desc);

// --- Задача 9.2 ---
double avgTempC(double arr[], int n);
double toFahrenheit(double c);

// --- Задача 9.3 ---
int bitTask(unsigned int N);

double s_calculation(double x, double y, double z);

// Прототипи функцій згідно із завданням 10.1 - 10.3
void task10_1(const std::string& inputPath, const std::string& outputPath);
void task10_2(const std::string& inputPath);
void task10_3(const std::string& outputPath, double x, double y, double z, unsigned int b);

#endif
