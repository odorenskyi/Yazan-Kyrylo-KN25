#ifndef MODULE_YAZAN_H_INCLUDED
#define MODULE_YAZAN_H_INCLUDED

#include "struct_type_project_5.h"

// Прототипы твоих функций
void searchByCode(Node* head);
void deleteEntity(Node*& head); // Передаем по ссылке (&), так как начало списка может удалиться
void saveToBinary(Node* head, const string& dbFilename);

#endif
