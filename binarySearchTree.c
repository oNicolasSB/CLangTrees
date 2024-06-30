#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinarySearchTree
{
    Node *root;
} BinarySearchTree;

BinarySearchTree *createBinarySearchTree()
{
    BinarySearchTree *tree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    return tree;
}

void insertRoot(BinarySearchTree *tree, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    tree->root = newNode;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertBinarySearchTree(BinarySearchTree *tree, int data)
{
    if (tree->root == NULL)
    {
        insertRoot(tree, data);
        return;
    }
    Node *current = tree->root;
    Node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return;
    }
    if (data < parent->data)
        parent->left = createNode(data);
    else
        parent->right = createNode(data);
}

Node *search(Node *node, int data)
{
    if (node == NULL || node->data == data)
        return node;

    if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

Node *searchBinarySearchTree(BinarySearchTree *tree, int data)
{
    return search(tree->root, data);
}

Node *getMin(Node *node)
{
    if (node == NULL)
        return node;
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node *getMinBinarySearchTree(BinarySearchTree *tree)
{
    return getMin(tree->root);
}

Node *getMax(Node *node)
{
    if (node == NULL)
        return node;
    while (node->right != NULL)
        node = node->right;
    return node;
}

Node *getMaxBinarySearchTree(BinarySearchTree *tree)
{
    return getMax(tree->root);
}

Node *removeNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;
    if (data < node->data)
        node->left = removeNode(node->left, data);
    else if (data > node->data)
        node->right = removeNode(node->right, data);
    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            Node *temp = getMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }
    return node;
}

void removeBinarySearchTree(BinarySearchTree *tree, int data)
{
    tree->root = removeNode(tree->root, data);
    return;
}

void inOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

void inOrderTraversalBinarySearchTree(BinarySearchTree *tree)
{
    inOrderTraversal(tree->root);
}

void postOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d", node->data);
}

void postOrderTraversalBinarySearchTree(BinarySearchTree *tree)
{
    postOrderTraversal(tree->root);
}

void preOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void preOrderTraversalBinarySearchTree(BinarySearchTree *tree)
{
    preOrderTraversal(tree->root);
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

int heightBinarySearchTree(BinarySearchTree *tree)
{
    return height(tree->root);
}
