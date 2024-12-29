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
}#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


int is_full() {
    return ((rear + 1) % SIZE == front);
}


int is_empty() {
    return (front == -1);
}


void insert(int value) {
    if (is_full()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}


void delete() {
    if (is_empty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}


void display() {
    if (is_empty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
