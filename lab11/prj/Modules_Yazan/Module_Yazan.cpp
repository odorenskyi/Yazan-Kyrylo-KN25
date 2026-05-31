#include "struct_type_project_5.h"
#include <fstream>

// Твой поиск
void searchByCode(Node* head) {
    if (head == nullptr) {
        cout << "Реєстр порожній." << endl;
        return;
    }
    int targetCode;
    cout << "Введіть код ЄДЕБО для пошуку: ";
    cin >> targetCode;

    Node* current = head;
    while (current != nullptr) {
        if (current->data.edeboCode == targetCode) {
            cout << "\n--- Запис знайдено ---" << endl;
            cout << "Код: " << current->data.edeboCode << endl;
            cout << "Назва: " << current->data.fullName << endl;
            cout << "Адреса: " << current->data.address << endl;
            return;
        }
        current = current->next;
    }
    cout << "Запис з кодом " << targetCode << " не знайдено." << endl;
}

// Твое удаление
void deleteEntity(Node*& head) {
    if (head == nullptr) {
        cout << "Реєстр порожній." << endl;
        return;
    }
    int targetCode;
    cout << "Введіть код ЄДЕБО для видалення: ";
    cin >> targetCode;

    if (head->data.edeboCode == targetCode) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Запис успішно видалено!" << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->data.edeboCode != targetCode) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Запис не знайдено." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Запис успішно видалено!" << endl;
}

// Твое сохранение базы данных
void saveToBinary(Node* head, const string& dbFilename) {
    ofstream outFile(dbFilename);
    if (!outFile.is_open()) return;

    Node* current = head;
    while (current != nullptr) {
        outFile << current->data.edeboCode << endl;
        outFile << current->data.fullName << endl;
        outFile << current->data.address << endl;
        outFile << current->data.phone << endl;
        outFile << current->data.email << endl;
        outFile << current->data.foundationYear << endl;
        current = current->next;
    }
    outFile.close();
}

// НОВОЕ: Автоматическая загрузка из файла при запуске
void loadFromFile(Node*& head, const string& dbFilename) {
    ifstream inFile(dbFilename);
    if (!inFile.is_open()) {
        cout << "Файл бази даних не знайдено. Створено новий пустий реєстр." << endl;
        return;
    }

    EducationRegistry temp;
    // Читаем до конца файла
    while (inFile >> temp.edeboCode) {
        inFile.ignore(); // Пропускаем Enter после числа
        getline(inFile, temp.fullName);
        getline(inFile, temp.address);
        getline(inFile, temp.phone);
        getline(inFile, temp.email);
        inFile >> temp.foundationYear;
        inFile.ignore();

        // Добавляем загруженный элемент (используем функцию напарника)
        addRecord(head, temp);
    }
    inFile.close();
    cout << "Дані успішно завантажено з файлу!" << endl;
}

// НОВОЕ: Вывод в текстовый файл по заданию
void printToFile(Node* head, const string& txtFilename) {
    ofstream outFile(txtFilename);
    if (!outFile.is_open()) {
        cout << "Помилка створення файлу!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        outFile << "Code: " << temp->data.edeboCode << endl;
        outFile << "Name: " << temp->data.fullName << endl;
        outFile << "Address: " << temp->data.address << endl;
        outFile << "Phone: " << temp->data.phone << endl;
        outFile << "Email: " << temp->data.email << endl;
        outFile << "Year: " << temp->data.foundationYear << endl;
        outFile << "------------------------" << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "Реєстр збережено у файл: " << txtFilename << endl;
}
