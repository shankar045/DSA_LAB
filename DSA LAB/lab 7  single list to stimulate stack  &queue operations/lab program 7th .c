#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return -1;
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

int peek(struct Node* top) {
    if (top == NULL) return -1;
    return top->data;
}

int isStackEmpty(struct Node* top) {
    return top == NULL;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) return -1;
    struct Node* temp = *front;
    int dequeuedData = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return dequeuedData;
}

int peekQueue(struct Node* front) {
    if (front == NULL) return -1;
    return front->data;
}

int isQueueEmpty(struct Node* front) {
    return front == NULL;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    printf("Popped from stack: %d\n", pop(&stackTop));
    printf("Top element of stack: %d\n", peek(stackTop));

    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    enqueue(&queueFront, &queueRear, 300);
    printf("Dequeued from queue: %d\n", dequeue(&queueFront, &queueRear));
    printf("Front element of queue: %d\n", peekQueue(queueFront));

    printf("Stack elements: ");
    printList(stackTop);
    printf("Queue elements: ");
    printList(queueFront);

    return 0;
}
