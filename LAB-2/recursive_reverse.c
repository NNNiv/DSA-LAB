#include <stdio.h>
int rev(int num);
void main()
{
    int num;
    printf("Enter a number ");
    scanf("%d", &num);

    printf("The reversed number is %d", rev(num));
}

int rev(int num)
{
    static int n = 0;
    if (num > 0)
        n = (n * 10) + (num % 10);
    else
        return n;
    return rev(num / 10);
}
