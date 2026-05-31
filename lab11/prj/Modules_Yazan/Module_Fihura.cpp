#include "struct_type_project_5.h"

void addRecord(Node*& head, EducationRegistry newRecord) {
    Node* newNode = new Node;
    newNode->data = newRecord;
    newNode->next = head;
    head = newNode;
}

void printRegistry(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << "Code: " << temp->data.edeboCode << endl;
        cout << "Name: " << temp->data.fullName << endl;
        cout << "Address: " << temp->data.address << endl;
        cout << "Phone: " << temp->data.phone << endl;
        cout << "Email: " << temp->data.email << endl;
        cout << "Year: " << temp->data.foundationYear << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}
