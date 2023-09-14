#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* head = NULL;

void create();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void traverse();

int main()
{
    int choice;

    while (1)
    {
        printf("1. Create\n2. Insert front\n3. Insert end\n4. Delete front\n5. Delete end\n6. Traverse\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            traverse();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}

void create()
{
    struct Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Node created\n");
    printf("Enter node value: ");
    scanf("%d", &temp->value);
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void insert_front()
{
    struct Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter node value: ");
    scanf("%d", &temp->value);
    printf("Node inserted\n");
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }

}

void insert_end()
{
    struct Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter node value: ");
    scanf("%d", &temp->value);
    printf("Node inserted\n");
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node* ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void delete_front()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        printf("Node deleted\n");
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->next == NULL)
    {
        struct Node *ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else
    {
        struct Node *ptr = head;
        struct Node *prev_ptr = NULL;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
    }
}

void traverse()
{
    if (head == NULL)
        printf("Linked list is empty\n");
    else {
        printf("Linked List: ");
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf(" %d -> ", ptr->value);
            ptr = ptr->next;
        }
        printf("NULL");
    }

    printf("\n");
}
