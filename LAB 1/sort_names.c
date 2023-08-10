#include <stdio.h> 
#include <string.h>

int main()
{
    char names[10][30];

    int n, i, j, x;
    printf("Enter the number of names (max 10): ");
    scanf("%d", &n);

    printf("Enter the names:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", names + i);
    }

    char temp[30];
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1 ; j < n; j++)
        {
            x = strcmp(*(names + i), *(names + j));
            if (x > 0)
            {
                strcpy(temp, *(names + i));
                strcpy(*(names + i), *(names + j));
                strcpy(*(names + j), temp);
            }
        }

    }
    printf("\n");
    printf("The sorted names are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", names + i);
    }

    return 0;
}
