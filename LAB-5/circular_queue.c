#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front = -1;
int rear = -1;
int circular_queue[MAX];
int i = 0;
int n;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Operation\n");
        }
    }
}

void enqueue()
{
    int item;
    if (i == n)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Enter the element to enqueue: ");
        scanf("%d", &item);
        rear = (rear + 1) % MAX;
        circular_queue[rear] = item;
        printf("%d was enqueued\n");
        i++;
    }
}
void dequeue()
{
    int num;
    if (i == 0)
        printf("Queue Underflow!\n");
    else
    {
        num = circular_queue[front];
        if (rear == front)
            rear = front = -1;
        else
        {
            front = (front + 1) % MAX;
            printf("%d was dequeued\n", num);
            i--;
        }
    }
}

void display()
{
    if (i == 0)
        printf("Queue is empty");
    else
    {
        int j;
        printf("Value at front of queue: %d\n", circular_queue[front]);

        for (j = front + 1; j != rear; j = (j + 1) % MAX)
            printf("\t\t\t %d\n", circular_queue[j]);

        printf("Value at rear of queue:  %d\n", circular_queue[rear]);
    }
}

