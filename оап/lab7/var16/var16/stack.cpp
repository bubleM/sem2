#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

void initStack(Stack* stack) {
    stack->top = nullptr;
}

bool isEmpty(Stack* stack) {
    return stack->top == nullptr;
}

void push(Stack* stack, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; 
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    delete temp;
    return poppedValue;
}

void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

void saveToFile(Stack* stack, const char* filename) {
   ofstream file(filename);
    if (file.is_open()) {
        Node* current = stack->top;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }
}

void loadFromFile(Stack* stack, const char* filename) {
    clear(stack); 
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            push(stack, value);
        }
        file.close();
    }
}

void removeFromStack3BasedOnStack2(Stack* stack1, Stack* stack2, Stack* stack3) {
    Node* current3 = stack3->top, * prev3 = nullptr;

    while (current3 != nullptr) {
        bool inStack1 = false;
        bool inStack2 = false;

        Node* current1 = stack1->top;
        while (current1 != nullptr) {
            if (current3->data == current1->data) {
                inStack1 = true;
                break;
            }
            current1 = current1->next;
        }

        Node* current2 = stack2->top;
        while (current2 != nullptr) {
            if (current3->data == current2->data) {
                inStack2 = true;
                break;
            }
            current2 = current2->next;
        }

        if (inStack2 && !inStack1) {
            cout << "Удален элемент из Stack3: " << current3->data << endl;
            if (prev3 == nullptr) {
                stack3->top = current3->next;
                delete current3;
                current3 = stack3->top; 
            }
            else {
                prev3->next = current3->next;
                delete current3;
                current3 = prev3->next; 
            }
        }
        else {
            prev3 = current3; 
            current3 = current3->next;
        }
    }
}

void removeFromStack3BasedOnStack1(Stack* stack1, Stack* stack2, Stack* stack3) {
    Node* current3 = stack3->top, * prev3 = nullptr;

    while (current3 != nullptr) {
        bool inStack1 = false;
        bool inStack2 = false;

        Node* current1 = stack1->top;
        while (current1 != nullptr) {
            if (current3->data == current1->data) {
                inStack1 = true;
                break;
            }
            current1 = current1->next;
        }

        Node* current2 = stack2->top;
        while (current2 != nullptr) {
            if (current3->data == current2->data) {
                inStack2 = true;
                break;
            }
            current2 = current2->next;
        }

        if (inStack1 && !inStack2) {
            cout << "Удален элемент из Stack3: " << current3->data << endl;
            if (prev3 == nullptr) {
                stack3->top = current3->next;
                delete current3;
                current3 = stack3->top;
            }
            else {
                prev3->next = current3->next;
                delete current3;
                current3 = prev3->next; 
            }
        }
        else {
            prev3 = current3; 
            current3 = current3->next;
        }
    }
}
