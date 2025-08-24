struct Stack
{
	int data; 
	Stack* next;
};
void show(Stack*& myStk);
void push(int x, Stack*& myStk); 
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk); 
void clear(Stack*& myStk); 
void find(Stack*& myStk); 