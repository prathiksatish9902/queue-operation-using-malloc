#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int *queue;
int size;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: display();
            break;
        case 4:
            free(queue);
            exit(0);
        default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue() {
    int x;
    if (rear == size - 1) {
        printf("Queue overflow\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &x);
        if (front == -1) front = 0;
        rear = rear + 1;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front = front + 1;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
