#ifndef STRUCT_TYPE_PROJECT_5_H
#define STRUCT_TYPE_PROJECT_5_H

#include <iostream>
#include <string>

using namespace std;

struct EducationRegistry {
    int edeboCode;
    string fullName;
    string address;
    string phone;
    string email;
    int foundationYear;
};

struct Node {
    EducationRegistry data;
    Node* next;
};

// --- Функции напарника ---
void addRecord(Node*& head, EducationRegistry newRecord);
void printRegistry(Node* head);

// --- Твои функции ---
void searchByCode(Node* head);
void deleteEntity(Node*& head);
void saveToBinary(Node* head, const string& dbFilename);

// --- Новые функции (для полного выполнения варианта 5) ---
void loadFromFile(Node*& head, const string& dbFilename);
void printToFile(Node* head, const string& txtFilename);

#endif
