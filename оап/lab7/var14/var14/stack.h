#pragma once
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void initStack(Stack& stack);
void push(Stack& stack, int value);
int pop(Stack& stack);
bool isEmpty(const Stack& stack);
void clear(Stack& stack);
void saveToFile(const Stack& stack, const string& filename);
void loadFromFile(Stack& stack, const string& filename);
void findDuplicates(const Stack& stack1, const Stack& stack2, Stack& duplicates);
void displayStack(const Stack& stack);
void saveStack2ToFile(const Stack& stack2, const string& filename);
void loadStack2FromFile(Stack& stack2, const string& filename);
