#include "ModulesYazan.h"
#include <iostream>
#include <fstream>

int main() {
    std::string testIn = "InVajyl.txt";
    std::string testOut = "OutVajyl.txt";

    // Підготовка вхідного файлу
    std::ofstream startFile(testIn);
    startFile << "Це тестова програма. Студент виконує модуль. Модульчик - це не те слово.";
    startFile.close();

    std::cout << "Running Task 10.1..." << std::endl;
    task10_1(testIn, testOut);

    std::cout << "Running Task 10.2..." << std::endl;
    task10_2(testIn);

    std::cout << "Running Task 10.3..." << std::endl;
    task10_3(testOut, 2.5, 3.0, 1.2, 255);

    std::cout << "Testing complete. Check " << testIn << " and " << testOut << std::endl;
    return 0;
}
