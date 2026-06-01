#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Необхідно для функції transform
#include <windows.h> // Необхідно для налаштування кодування консолі
#include "ModulesYazan.h"

using namespace std;

// Функція для генерації 100 звукових сигналів
void play100Beeps() {
    for(int i = 0; i < 100; i++) {
        cout << "\a";
    }
}

// Локальна функція для тестування
void runUnitTests() {
    // Вказуємо шлях до файлу (.. означає вийти на папку вище)
    ofstream logFile("..\\..\\TestSuite\\TestResults.txt", ios::app);

    if(logFile.is_open()) {
        ClassLab12_Yazan book; // Створюємо об'єкт за замовчуванням

        // Тест 1: Перевірка формули площі (S = 17 * 24 = 408)
        logFile << "TC_01 -> getCoverArea() -> 408 -> ";
        if (book.getCoverArea() == 408) logFile << "PASS\n"; else logFile << "FAIL\n";

        // Тест 2: Перевірка захисту від некоректних даних
        // Ми намагаємося встановити від'ємні значення, які клас має відхилити
        book.setDimensions(-10, -20);
        logFile << "TC_02 -> setDimensions(-10, -20) (Validation) -> ";
        if (book.getWidth() != -10) logFile << "PASS\n"; else logFile << "FAIL\n";

        // Тест 3: Перевірка роботи з назвою
        book.setTitle("TestBook");
        logFile << "TC_03 -> setTitle(\"TestBook\") -> getTitle() -> ";
        if (book.getTitle() == "TestBook") logFile << "PASS\n"; else logFile << "FAIL\n";

        logFile << "-----------------------------------\n"; // Розділювач для зручності

        cout << "Тестування успішно записано у TestResults.txt" << endl;
        logFile.close();
    } else {
        cout << "Помилка: не вдалося відкрити файл у папці TestSuite!" << endl;
    }
}

int main() {
    // Виправлення кракозябр: встановлюємо Windows-1251 кодування для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. Видаємо 100 звукових сигналів
    play100Beeps();

    // 2. Отримуємо шлях до поточного файлу
    string filePath = __FILE__;

    // 3. Перетворюємо весь шлях у нижній регістр, щоб уникнути помилок з Lab12 / lab12
    string filePathLower = filePath;
    transform(filePathLower.begin(), filePathLower.end(), filePathLower.begin(), ::tolower);

    // 4. Перевіряємо, чи знаходиться файл у \lab12\prj
    if (filePathLower.find("lab12\\prj") == string::npos && filePathLower.find("lab12/prj") == string::npos) {

        // Якщо вимоги дійсно порушено
        ofstream errFile("TestResults.txt");
        if (errFile.is_open()) {
            errFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!\n";
            errFile.close();
        }
        cout << "Помилка директорії! Див. TestResults.txt" << endl;

    } else {
        // Якщо шлях правильний — запускаємо тести
        runUnitTests();
    }

    return 0;
}
