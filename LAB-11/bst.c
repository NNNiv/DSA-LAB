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

void inorder(struct Node* root)
{
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
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

struct Node* delete(struct Node* root, int k)
{
  if (root == NULL)
    return root;

  if (root->key > k) {
    root->left = delete(root->left, k);
    return root;
  }
  else if (root->key < k) {
    root->right = delete(root->right, k);
    return root;
  }

  if (root->left == NULL) {
    struct Node* temp = root->right;
    free(root);
    return temp;
  }
  else if (root->right == NULL) {
    struct Node* temp = root->left;
    free(root);
    return temp;
  }

  else {

    struct Node* succParent = root;

    struct Node* succ = root->right;
    while (succ->left != NULL) {
      succParent = succ;
      succ = succ->left;
    }

    if (succParent != root)
      succParent->left = succ->right;
    else
      succParent->right = succ->right;

    root->key = succ->key;

    free(succ);
    return root;
  }
}

struct Node* search(struct Node* root, int key)
{
  if (root == NULL || root->key == key)
    return root;

  if (root->key < key)
    return search(root->right, key);

  return search(root->left, key);
}

int main()
{
  int choice, element;
  struct Node* root = NULL;

  printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");

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
        printf("Enter element to delete: ");
        scanf("%d", &element);
        struct Node* temp;
        temp = delete(root, element);
        if (temp == root) 
          printf("Element not found in BST\n");
        else
        {
          root = temp;
          printf("Node deleted\n");
        }

        break;
      case 3:
        printf("Enter element to search: ");
        scanf("%d", &element);
        struct Node* result;
        result = search(root, element);
        if (result != NULL)
          printf("Element found in BST\n");
        else
          printf("Element not found in BST\n");
        break;
      case 4:
        printf("Inorder traversal of the BST: ");
        inorder(root);
        printf("\n");
        break;
      case 5:
        exit(0);
      default:
        printf("\nInvalid choice\n");
    }
  }
    return 0;
}
