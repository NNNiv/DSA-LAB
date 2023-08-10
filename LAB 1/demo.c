// Demo program to swap two numbers to showcase pointers
#include <stdio.h>

void swap(int *x, int *y);

int main() 
{
    int a, b;
    int *x, *y;
    x = &a;
    y = &b;

    printf("Enter two numbers: ");
    scanf("%d %d", x, y);

    swap(x, y);
    printf("The swapped numbers are %d and %d", a, b);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}