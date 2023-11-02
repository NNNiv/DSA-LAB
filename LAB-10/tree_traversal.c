#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

node* create();
void traverse_pre();
void traverse_in();
void traverse_post();


int main()
{
    // root
    node* root = create(1);

    // level 1
    root->left = create(2);
    root->right = create(3);

    // level 2
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);

    // level 3
    root->right->left->left = create(7);

    // level 4
    root->right->left->left->left = create(8);
    root->right->left->left->right= create(9);

    printf("\nPreorder traversal: ");
    traverse_pre(root);

    printf("\nInorder traversal: ");
    traverse_in(root);

    printf("\nPostorder traversal: ");
    traverse_post(root);
    return 0;

}

node* create(int value)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void traverse_pre(node* temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->value);
    traverse_pre(temp->left);
    traverse_pre(temp->right);
}

void traverse_in(node* temp)
{
    if (temp == NULL)
        return;
    traverse_in(temp->left);
    printf("%d ", temp->value);
    traverse_in(temp->right);
}

void traverse_post(node* temp)
{
    if (temp == NULL)
        return;
    traverse_post(temp->left);
    traverse_post(temp->right);
    printf("%d ", temp->value);
}





