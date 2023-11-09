#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int key;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int item)
{
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct Node* findMax(struct Node* root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Node* findMin(struct Node* root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}
struct Node* insert(struct Node* node, int key)
{
  if (node == NULL)
    return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

int main()
{
  int choice, element;
  struct Node* root = NULL;

  printf("1. Insert\n2. Find Min\n3. Find Max\n4. Exit\n");

  while (1)
  {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        printf("Enter element to insert: ");
        scanf("%d", &element);
        root = insert(root, element);
        printf("Node inserted\n");
        break;

      case 2:
        struct Node* temp;
        temp = findMin(root);
        printf("Minimum value of BST is: %d\n", temp->key);
        break;
      case 3:
        temp = findMax(root);
        printf("Maximum value of BST is: %d\n" , temp->key);
        break;
      case 4:
        exit(0);
      default:
        printf("\nInvalid choice\n");
        break;
    }
  }
    return 0;
}
