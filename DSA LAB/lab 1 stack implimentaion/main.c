#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int stack[SIZE];
int top = -1;

void push(int element) {
if (top == SIZE - 1) {
printf("Stack Overflow! Cannot push %d\n", element);
} else {
top++;
stack[top] = element;
printf("%d pushed to stack\n", element);
}
}

int pop() {
if (top == -1) {
printf("Stack Underflow! No element to pop\n");
return -1;
} else {

int poppedElement = stack[top];
top--;
return poppedElement;
}
}

int peek() {
if (top == -1) {
printf("Stack is empty\n");
return -1;
} else {
return stack[top];
}
}

int isEmpty() {
return top == -1;
}

int isFull() {
return top == SIZE - 1;
}

void display() {
if (top == -1) {


printf("Stack is empty\n");
} else {
printf("Stack elements are:\n");
for (int i = top; i >= 0; i--) {
printf("%d\n", stack[i]);
}
}
}

int main() {

push(10);
push(20);
push(30);
push(40);
push(50);

printf("\nTop element is: %d\n", peek());

printf("Is stack full? %s\n", isFull() ? "true" : "false");
printf("Is stack empty? %s\n", isEmpty() ? "true" : "false");

printf("\nPopped element: %d\n", pop());
printf("Popped element: %d\n", pop());

display();

return 0; 
}
