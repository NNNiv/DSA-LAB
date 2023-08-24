#include <stdio.h>
#include <stdlib.h>
#define N 20

int stack[N];
int n;
int top = -1;


void push();
void pop();
void display();


int main()
{
    printf("Enter the length of the stack (max 20): ");
    scanf("%d", &n);
    printf("Stack of size %d created\n", n);

    int choice;
    while (1)
    {
        printf("Which operation would you like to perform?\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;
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
    if (top >= n - 1) 
        printf("Stack Overflow\n");
    else 
    {
        int item;
        printf("Enter item to push to the stack: ");
        scanf("%d", &item);
        stack[++top] = item;
        printf("Entered %d into stack\n", item);
    }
}

void pop()
{
    if (top < 0)
        printf("Stack Underflow\n");
    else 
    {
        printf("Removed %d from stack\n", stack[top]);
        top--;
    }
}

void display()
{
    printf("The contents of the stack are: \n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);

}