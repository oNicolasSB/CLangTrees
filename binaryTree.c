#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinaryTree
{
    Node *root;
} BinaryTree;

BinaryTree *createBinaryTree()
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->root = NULL;
    return tree;
}

void insertRoot(BinaryTree *tree, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    tree->root = newNode;
}

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertRight(Node *node, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    node->right = newNode;
}

void insertLeft(Node *node, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    node->left = newNode;
}

void inOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%c", node->data);
    inOrderTraversal(node->right);
}

void inOrderTraversalBinaryTree(BinaryTree *tree)
{
    inOrderTraversal(tree->root);
}

void postOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%c", node->data);
}

void postOrderTraversalBinaryTree(BinaryTree *tree)
{
    postOrderTraversal(tree->root);
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int heightBinaryTree(BinaryTree *tree)
{
    return height(tree->root);
}


