#include<stdio.h>
#include<stdlib.h>
#define m 10
typedef struct node{
    int data;
    struct node* next;
}node;
node* newnode(int key){
    node* newnode = malloc(sizeof(node));
    newnode->data = key;
    newnode->next = NULL;
    return newnode;
}
node* hashtable[m];
int opcount = 0;
int hashfunction(int key){
    return key % m;
}
void insert(int key){
    int index = hashfunction(key);
    node* cell = newnode(key);
    if(hashtable[index] == NULL)
        hashtable[index] = cell;
    else{
        node* temp = hashtable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = cell;
    }
}
void display(){
    for(int i = 0; i < m; i++){
        node* temp = hashtable[i];
        printf("\n%d", i);
        while(temp != NULL){
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
    }
}
int search(int key){
    int index = hashfunction(key);
    node* temp = hashtable[index];
    while(temp != NULL){
        opcount++;
        if(temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}
void main(){
    for(int i = 0; i < m; i++)
        hashtable[i] = NULL;
    int n, key;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key);
        insert(key);
    }
    display();
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    printf(search(key) ? "Found" : "Not found");
    printf("\nOpcount: %d\n", opcount);
}