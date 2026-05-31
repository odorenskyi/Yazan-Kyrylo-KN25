#include "struct_type_project_5.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* registryHead = nullptr;      // Создаем пустой список (поезд без вагонов)
    const string dbFile = "data.txt";  // Файл, где мы храним базу между запусками

    cout << "--- ЗАПУСК ПРОГРАМИ ---" << endl;
    // 1. Автоматическая загрузка (условие из картинки)
    loadFromFile(registryHead, dbFile);

    int choice;
    do {
        // 2. Рисуем меню
        cout << "\n===== МЕНЮ =====" << endl;
        cout << "1. Вивести реєстр на екран" << endl;
        cout << "2. Вивести реєстр у текстовий файл" << endl;
        cout << "3. Додати новий запис" << endl;
        cout << "4. Пошук за кодом ЄДЕБО" << endl;
        cout << "5. Видалити запис" << endl;
        cout << "0. Вийти з програми (з автозбереженням)" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        // 3. Вызываем нужный модуль в зависимости от выбора
        switch(choice) {
            case 1:
                printRegistry(registryHead);
                break;
            case 2: {
                string filename;
                cout << "Введіть ім'я файлу (наприклад, output.txt): ";
                cin >> filename;
                printToFile(registryHead, filename);
                break;
            }
            case 3: {
                EducationRegistry newRec;
                cout << "Введіть код ЄДЕБО: ";
                cin >> newRec.edeboCode;
                cin.ignore(); // Очищаем буфер после ввода числа
                cout << "Введіть назву: ";
                getline(cin, newRec.fullName); // getline позволяет вводить текст с пробелами
                cout << "Введіть адресу: ";
                getline(cin, newRec.address);
                cout << "Введіть телефон: ";
                getline(cin, newRec.phone);
                cout << "Введіть email: ";
                getline(cin, newRec.email);
                cout << "Введіть рік заснування: ";
                cin >> newRec.foundationYear;

                addRecord(registryHead, newRec);
                cout << "Запис успішно додано!" << endl;
                break;
            }
            case 4:
                searchByCode(registryHead);
                break;
            case 5:
                deleteEntity(registryHead);
                break;
            case 0:
                // 4. Автоматическое сохранение перед выходом
                saveToBinary(registryHead, dbFile);
                cout << "Дані збережено. Роботу завершено." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while(choice != 0); // Крутим цикл, пока пользователь не нажмет 0

    return 0;
}
