#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int n; 
// Enqueue operation to insert an element at the rear of the queue
void enqueue() {
    if ((rear + 1) % n == front) {
        printf("Queue Overflow.\n");
    } else {
        int value;
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % n;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Dequeue operation to remove an element from the front of the queue
int dequeue() {
    int value;
    if (front == -1) {
        printf("Queue Underflow.\n");
        return -1; // or some sentinel value
    } else {
        value = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }
    }
    return value;
}

// Display the entire queue
void displayQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d", queue[i]);
        printf("\n");
    }
}

int main() {
    printf("Enter size of queue: ");
    scanf("%d", &n);
    int choice;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                int value;
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
