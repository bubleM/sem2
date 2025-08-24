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
        cout<<"������: ���� ����."<<endl;
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

void findDuplicates(const Stack& stack1, const Stack& stack2, Stack& duplicates) {
    unordered_set<int> elements;

    Node* current = stack1.top;
    while (current != nullptr) {
        elements.insert(current->data);
        current = current->next;
    }

    current = stack2.top;
    while (current != nullptr) {
        if (elements.find(current->data) != elements.end()) {
            push(duplicates, current->data);
        }
        current = current->next;
    }
}

void displayStack(const Stack& stack) {
    Node* current = stack.top;
    if (isEmpty(stack)) {
       cout << "���� ����." << endl;
        return;
    }

    std::cout << "�������� �����: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void saveStack2ToFile(const Stack& stack2, const string& filename) {
    saveToFile(stack2, filename); 
}

void loadStack2FromFile(Stack& stack2, const string& filename) {
    loadFromFile(stack2, filename); 
}
