#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* top = NULL;
int length = 0;
int max_length;

void push();
void pop();
void display();

int main()
{
    printf("Enter the length of the stack: ");
    scanf("%d", &max_length);
    int choice;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (length == max_length)
            {
                printf("Stack Overflow\n");
                break;
            }
            else
            {
                push();
                break;
            }
        case 2:
            pop();
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

void push()
{

    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter value to push: ");
    scanf("%d", &temp->value);
    length++;
    temp->next = NULL;
    if (top == NULL)
        top = temp;
    else
    {
        struct Node* ptr = top;
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        struct Node *ptr = top;
        int val = top->value;
        top = top->next;
        free(ptr);
        printf("Popped %d from stack\n", val);
    }
}

void display()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        printf("Contents of the stack:\n\n");
        struct Node *ptr = top;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->value);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
