#include <stdio.h>
#include <stdlib.h>

#define N 20
int n;

struct Stack 
{
    int arr[N];
    int top;
} stk;

void push(struct Stack *stk);
void pop(struct Stack *stk);
void display(struct Stack *stk);

int main()
{
    stk.top = -1;
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
                push(&stk);
                break;
            case 2:
                pop(&stk);
                break;
            case 3:
                display(&stk);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

void push(struct Stack *stk)
{
    if (stk->top >= n - 1)
        printf("Stack Overflow\n");
    else {
        int item;
        printf("Enter item to push: ");
        scanf("%d", &item);
        stk->top++;
        stk->arr[stk->top] = item;
        printf("Pushed %d to the stack\n", item);
    }
}

void pop(struct Stack *stk)
{
    if (stk->top < 0) 
        printf("Stack Underflow\n");
    else {
        printf("Removed %d from stack\n", stk->arr[stk->top]);
        stk->top--;
    }
}

void display(struct Stack *stk) 
{
    printf("The elements of the stack are:\n");
    for (int i = stk->top; i >=0; i--)
        printf("%d\n", stk->arr[i]);
}