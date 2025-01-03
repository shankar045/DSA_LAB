#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void insert(int item) {
if (rear == QUEUE_SIZE - 1) {
printf("Queue Overflow! Cannot insert %d.\n", item);
return;
}
if (front == -1) {

front = 0;
}
rear++;
queue[rear] = item;
printf("Inserted: %d\n", item);
}

int delete() {
if (front == -1 || front > rear) {
printf("Queue Underflow! Queue is empty.\n");
return -1;
}
int deletedItem = queue[front];
printf("Deleted: %d\n", deletedItem);
front++;

if (front > rear) {
front = rear = -1;
}
return deletedItem;
}

void display() {
if (front == -1 || front > rear) {
printf("Queue is empty.\n");
return;
}
printf("Queue contains: ");
for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}

int main() {
int choice, item;

while (1) {
printf("\nQueue Operations:\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");


scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter the element to insert: ");
scanf("%d", &item);
insert(item);
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf("Exiting program.\n");
exit(0);
break;
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
