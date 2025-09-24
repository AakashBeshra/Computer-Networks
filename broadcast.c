//Take an example subnet of hosts and obtain a broadcast tree for the subnet
#include <stdio.h>
#include <stdlib.h>
// Define a structure for each node in the broadcast tree
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;
// Function to create a new node with given data
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to perform a broadcast using a broadcast tree
void broadcast(Node* root, int message)
{
    if (root == NULL)
    {
    return;
    }
 // Print the message for the current node
    printf("Node %d received message: %d\n", root->data, message);
 // Recursive broadcast to left and right subtrees
    broadcast(root->left, message);
    broadcast(root->right, message);
}

int main() {
 // Creating a sample broadcast tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
 // Broadcasting a message to the entire tree
    int message = 100;
    printf("Broadcasting message: %d\n", message);
    broadcast(root, message);
    return 0;
}


// Create a tree using start topology architecture (9 nodes) to sublevels, and transfer the data "Hello"