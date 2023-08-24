#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int* ptr1;
    int* ptr2;

    printf("Demonstarting calloc\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);

    ptr1 = (int*) calloc(n, sizeof(int));

    if (ptr1 == NULL)
        printf("Memory not allocated ");
    else
        printf("Memory allocated using calloc\n");

    for (i = 0; i < n; i++)
        ptr1[i] = i+1;

    printf("The elements of the array are: ");

    for (i = 0;i < n; i++)
        printf("%d ", ptr1[i]);
    

    printf("\n\nEnter the new size of the array: ");
    scanf("%d", &n);

    // Dynamically re-allocate memory using realloc()
    ptr1 = realloc(ptr1, n * sizeof(int));
    printf("Memory successfully re-allocated using realloc\n");

    for (i = 0; i < n; i++) 
        ptr1[i] = i + 1;

    printf("The elements of the array are: ");
    for (i = 0; i < n; i++) 
        printf("%d ", ptr1[i]);

    printf("\n");

    printf("\nDemonstarting malloc\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);

    ptr2 = (int *)malloc(n * sizeof(int));
    if (ptr2 == NULL)
        printf("Memory not allocated\n");
    else
        printf("Memory allocated using malloc\n");

    for (i = 0; i < n; i++)
        ptr2[i] = i + 1;

    printf("The elements of the array are : ");
    for (i = 0; i < n; i++)
        printf("%d ", *(ptr2 + i));
    
    printf("\n");

    free(ptr1);
    printf("\nCalloc memory successfully freed\n");
    free(ptr2);
    printf("Malloc memory successfully freed\n");

    return 0;
}
