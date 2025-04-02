#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Structure to represent a node in the Huffman tree
typedef struct Node {
    char data;
    float frequency; // Changed to float
    struct Node *left, *right;
} Node;

// Structure to represent a min heap
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node **array;
} MinHeap;

// Function to create a new node
Node *newNode(char data, float frequency) { // Changed to float
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to create a min heap of given capacity
MinHeap *createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node **)malloc(minHeap->capacity * sizeof(Node *));
    return minHeap;
}

// Function to swap two nodes
void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to min heapify a subtree rooted with given index
void minHeapify(MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size of heap is 1
int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// Function to extract minimum value from min heap
Node *extractMin(MinHeap *minHeap) {
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to min heap
void insertMinHeap(MinHeap *minHeap, Node *node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build min heap
MinHeap *buildMinHeap(char data[], float frequency[], int size) { // Changed to float
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], frequency[i]);
    minHeap->size = size;

    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

// Function to build Huffman tree
Node *buildHuffmanTree(char data[], float frequency[], int size) { // Changed to float
    Node *left, *right, *top;
    MinHeap *minHeap = buildMinHeap(data, frequency, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print Huffman codes from the root of Huffman Tree
void printCodes(Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left || root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int size;
    printf("Enter the number of characters: ");
    scanf("%d", &size);

    char *data = (char *)malloc(size * sizeof(char));
    float *frequency = (float *)malloc(size * sizeof(float)); // Changed to float

    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < size; ++i) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &data[i]);
        printf("Frequency %d: ", i + 1);
        scanf("%f", &frequency[i]); // Changed to %f
    }

    Node *root = buildHuffmanTree(data, frequency, size);

    int arr[100], top = 0;
    printCodes(root, arr, top);

    free(data);
    free(frequency);

    return 0;
}