struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void initStack(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void clear(Stack* stack);
void saveToFile(Stack* stack, const char* filename);
void loadFromFile(Stack* stack, const char* filename);
void removeFromStack3BasedOnStack2(Stack* stack1, Stack* stack2, Stack* stack3);
void removeFromStack3BasedOnStack1(Stack* stack1, Stack* stack2, Stack* stack3);