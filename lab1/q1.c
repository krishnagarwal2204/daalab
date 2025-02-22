#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
void processKey(struct Node** root, int key) {
    struct Node* res = search(*root, key);
    if (res != NULL) {
        printf("key found\n");
    } else {
        *root = insert(*root, key);
    }
}
int main() {
    struct Node* root = NULL;
    int n, key, choice;
    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);
    printf("Enter the initial keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    while (1) {
        printf("\nEnter 1 to search and insert a key\n");
        printf("Enter 2 to display tree traversals\n");
        printf("Enter 3 to exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the key to search or insert: ");
            scanf("%d", &key);
            processKey(&root, key);
        } else if (choice == 2) {
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}