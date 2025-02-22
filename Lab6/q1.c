#include <stdio.h>
#include <stdlib.h>
int opcount=0;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int countnodes(struct TreeNode * root){
    opcount++;
    if(root==NULL)
        return 0;
    int l=countnodes(root->left);
    int r=countnodes(root->right);
    return 1+l+r;
}
struct TreeNode* createbt() {
    int value;
    printf("Enter value for node (enter -1 for no node): ");
    scanf("%d", &value);
    if (value == -1) {
        return NULL;
    }
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Enter left child of %d:\n", value);
    newNode->left = createbt();
    printf("Enter right child of %d:\n", value);
    newNode->right = createbt();
    return newNode;
}
int main() {
    struct TreeNode* root = createbt();
    printf("The tree contains %d nodes.",countnodes(root));
    printf("\nOpcount: %d",opcount);
    return 0;
}
