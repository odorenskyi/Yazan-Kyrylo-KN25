#ifndef MODULESYAZAN_H
#define MODULESYAZAN_H

#include <string>

// Створення класу за вимогами лабораторної роботи
class ClassLab12_Yazan {
private:
    // Всі дані-члени класу є закритими (private)
    double width;  // ширина книги (a)
    double height; // висота книги (b)
    std::string title;

public:
    // Початкова ініціалізація атрибутів конструктором з параметрами за замовчуванням
    ClassLab12_Yazan(std::string bookTitle = "The C++ Programming Language", double w = 17.0, double h = 24.0);

    // Функції для надання значень атрибутів (читання)
    double getWidth();
    double getHeight();
    std::string getTitle();

    // Функція для надання значення площі палітурки
    double getCoverArea();

    // Функції для зміни значень із валідацією вхідних даних
    void setDimensions(double w, double h);
    void setTitle(std::string bookTitle);
};


// Конструктор ініціалізує об'єкт[cite: 1]
ClassLab12_Yazan::ClassLab12_Yazan(std::string bookTitle, double w, double h) {
    title = bookTitle;
    // Валідація: розміри не можуть бути від'ємними або нульовими
    if (w > 0 && h > 0) {
        width = w;
        height = h;
    } else {
        width = 17.0;
        height = 24.0;
    }
}

// Надання значень (гетери)[cite: 1]
double ClassLab12_Yazan::getWidth() {
    return width;
}

double ClassLab12_Yazan::getHeight() {
    return height;
}

std::string ClassLab12_Yazan::getTitle() {
    return title;
}

// Обчислення площі прямокутника: S = a * b[cite: 1]
double ClassLab12_Yazan::getCoverArea() {
    return width * height;
}

// Зміна значень (сетери) з перевіркою (валідацією)[cite: 1]
void ClassLab12_Yazan::setDimensions(double w, double h) {
    if (w > 0 && h > 0) {
        width = w;
        height = h;
    }
}

void ClassLab12_Yazan::setTitle(std::string bookTitle) {
    title = bookTitle;
}

#endif // MODULESYAZAN_H
