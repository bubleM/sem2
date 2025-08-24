#include "stack.h"
using namespace std;

void initStack(Stack& stack) {
    stack.top = nullptr;
}

void push(Stack& stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

int pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout<<"Ошибка: стек пуст."<<endl;
    }
    Node* temp = stack.top;
    int value = temp->data;
    stack.top = stack.top->next;
    delete temp;
    return value;
}

bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

void clear(Stack& stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

void saveToFile(const Stack& stack, const string& filename) {
   ofstream outFile(filename);
    Node* current = stack.top;
    while (current != nullptr) {
        outFile << current->data << endl;
        current = current->next;
    }
}

void loadFromFile(Stack& stack, const string& filename) {
    ifstream inFile(filename);
    int value;
    while (inFile >> value) {
        push(stack, value);
    }
}

void splitStack(const Stack& original, Stack& evenStack, Stack& oddStack) {
    Node* current = original.top;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            push(evenStack, current->data);
        }
        else {
            push(oddStack, current->data);
        }
        current = current->next;
    }
}

void displayStack(const Stack& stack) {
    Node* current = stack.top;
    if (isEmpty(stack)) {
        cout << "Стек пуст." << endl;
        return;
    }

    cout << "Элементы стека: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
