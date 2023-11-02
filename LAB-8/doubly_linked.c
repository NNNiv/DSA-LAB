// I yoinked this from my roommate

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert_at_beginning(int ele) {
    struct Node* newn;
    newn = (struct Node*)malloc(sizeof(struct Node));

    if (newn == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    if (head == NULL) {
        newn->data = ele;
        newn->next = NULL;
        newn->prev = NULL;
        head = newn;
    } else {
        newn->data = ele;
        newn->next = head;
        newn->prev = NULL;
        head->prev = newn;
        head = newn;
    }
}

void insert_at_end(int ele) {
    struct Node* newn;
    newn = (struct Node*)malloc(sizeof(struct Node));

    if (newn == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    if (head == NULL) {
        newn->data = ele;
        newn->next = NULL;
        newn->prev = NULL;
        head = newn;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newn->data = ele;
        newn->next = NULL;
        newn->prev = temp;
        temp->next = newn;
    }
}

void insert_at_pos(int ele, int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newn;
    newn = (struct Node*)malloc(sizeof(struct Node));

    if (newn == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    if (pos == 0) {
        insert_at_beginning(ele);
    } else {
        struct Node* temp = head;
        int i;
        for (i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of bounds!\n");
            free(newn);
            return;
        }

        newn->data = ele;
        newn->next = temp->next;
        newn->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newn;
        }
        temp->next = newn;
    }
}

void delete_at_front() {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* temp = head;
    int ele = temp->data;
    head = temp->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Element deleted: %d\n", ele);
}

void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    if (head->next == NULL) {
        int ele = head->data;
        free(head);
        head = NULL;
        printf("The element deleted: %d\n", ele);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    int ele = temp->data;
    temp->prev->next = NULL;
    free(temp);
    printf("The element deleted: %d\n", ele);
}

void delete_at_pos(int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 0) {
        delete_at_front();
        return;
    }

    struct Node* temp = head;
    int i;
    for (i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void display() {
    struct Node* trav = head;
    if (trav == NULL) {
        printf("The list is Empty!\n");
    } else {
        printf("The elements of the linked list are:");
        while (trav != NULL) {
            printf(" %d", trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, ele, pos, posd;
    printf("1 - Insert at front\n2 - Insert at end\n3 - Insert in middle\n4 - Delete from front\n5 - Delete from end\n6 - Delete from middle\n7 - Display\n8 - Exit\n");
    do {
        printf("\nEnter the choice of operation: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &ele);
                insert_at_beginning(ele);
                break;
            case 2:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &ele);
                insert_at_end(ele);
                break;
            case 3:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &ele);
                printf("\nEnter the position at which the element should be inserted: ");
                scanf("%d", &pos);
                insert_at_pos(ele, pos);
                break;
            case 4:
                delete_at_front();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter the position from where the element should be deleted: ");
                scanf("%d", &posd);
                delete_at_pos(posd);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (ch != 8);

    return 0;
}
