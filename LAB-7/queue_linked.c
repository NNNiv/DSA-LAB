#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* head = NULL;
int length = 0;
int max_length;

void enqueue();
void dequeue();
void display();

int main()
{
    printf("Enter the length of the queue: ");
    scanf("%d", &max_length);
    int choice;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (length == max_length)
            {
                printf("Queue Overflow\n");
                break;
            }
            else
            {
                enqueue();
                break;
            }
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

void enqueue()
{
    struct Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter value to enqueue: ");
    scanf("%d", &temp->value);
    length++;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        struct Node* ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void dequeue()
{
    if (head == NULL)
        printf("Queue underflow \n");
    else
    {
        struct Node *ptr = head;
        int val = head->value;
        head = head->next;
        free(ptr);
        printf("Dequeued %d\n", val);
    }
}

void display()
{
    if (head == NULL)
        printf("Queue is empty\n");
    else {
        printf("\nContents of the queue:\n");
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->value);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
