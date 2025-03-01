#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* maxValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
struct Node* successor(struct Node* root, int key) {
    struct Node* current = root;
    struct Node* successor = NULL;
    while (current != NULL) {
        if (key < current->key) {
            successor = current; 
            current = current->left;
        } else if (key > current->key)
            current = current->right;
        else
            break;  
    }
    if (current == NULL)
        return NULL; 
    if (current->right != NULL)
        return minValueNode(current->right);
    return successor;
}
struct Node* predecessor(struct Node* root, int key) {
    struct Node* current = root;
    struct Node* predecessor = NULL;
    while (current != NULL) {
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
        {
            predecessor = current;
            current = current->right;
        }
        else
            break;
    }
    if (current == NULL)
        return NULL;
    if (current->left != NULL)
        return maxValueNode(current->left);
    return predecessor;
}

int main()
{
  struct Node *root = NULL;
  int x,ch;
  do{
  printf("Enter 1 to insert a node,2 to view the preorder traversal,3 to find predecessor,4 to find successor and 5 to exit\n");
  scanf("%d",&ch);
  switch(ch){
  case 1: printf("Insert key\n");
          scanf("%d",&x);
          root=insert(root,x);
          break;
  case 2:printf("Preorder traversal:\n");
         preOrder(root);
         printf("\n");
         break;
  case 3:printf("Insert key\n");
          scanf("%d",&x);
          printf("Predecessor:%d\n",predecessor(root,x)->key);
          break;
    case 4:printf("Insert key\n");
          scanf("%d",&x);
          printf("Succesor:%d\n",successor(root,x)->key);
          break;
    case 5:break;
  }
}while(ch!=-1);
  return 0;
}
