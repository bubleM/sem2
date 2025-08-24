#pragma once
using namespace std;


#include <iostream>
#include <fstream>

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
void splitStack(const Stack& original, Stack& evenStack, Stack& oddStack);
void displayStack(const Stack& stack);


