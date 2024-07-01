#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct AVLBinarySearchTree
{
    Node *root;
} AVLBinarySearchTree;

AVLBinarySearchTree *createAVLBinarySearchTree()
{
    AVLBinarySearchTree *tree = (AVLBinarySearchTree *)malloc(sizeof(AVLBinarySearchTree));
    tree->root = NULL;
    return tree;
}

void insertRoot(AVLBinarySearchTree *tree, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    tree->root = newNode;
}

int getNodeHeight(Node *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return abs(getNodeHeight(node->left) - getNodeHeight(node->right));
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

Node *rotateLeft(Node *root)
{
    Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    newRoot->height = max(getNodeHeight(newRoot->left), getNodeHeight(newRoot->right)) + 1;
    return newRoot;
}

Node *rotateRight(Node *root)
{
    Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    newRoot->height = max(getNodeHeight(newRoot->left), getNodeHeight(newRoot->right)) + 1;
    return newRoot;
}

Node *rotateLeftRight(Node *root)
{
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

Node *rotateRightLeft(Node *root)
{
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1)
    {
        if (getNodeHeight(node->left) > getNodeHeight(node->right))
        {
            if (data < node->left->data)
                return rotateRight(node); // Rotação simples para a direita
            else
                return rotateLeftRight(node); // Rotação dupla esquerda-direita
        }
        else
        {
            if (data > node->right->data)
                return rotateLeft(node); // Rotação simples para a esquerda
            else
                return rotateRightLeft(node); // Rotação dupla direita-esquerda
        }
    }
    return node;
}

void insertAVLBinarySearchTree(AVLBinarySearchTree *tree, int data)
{
    if (tree->root == NULL)
    {
        insertRoot(tree, data);
        return;
    }
    tree->root = insert(tree->root, data);
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

Node *searchAVLBinarySearchTree(AVLBinarySearchTree *tree, int data)
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

Node *getMinAVLBinarySearchTree(AVLBinarySearchTree *tree)
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

Node *getMaxAVLBinarySearchTree(AVLBinarySearchTree *tree)
{
    return getMax(tree->root);
}

Node *removeNode(Node *node, int data)
{
    if (node == NULL)
        return node;

    if (data < node->data)
    {
        node->left = removeNode(node->left, data);
        if (getBalanceFactor(node) > 1)
        {
            if (getNodeHeight(node->right->left) <= getNodeHeight(node->right->right))
                node = rotateLeft(node);
            else
                node = rotateRightLeft(node);
        }
    }
    if (data > node->data)
    {
        node->right = removeNode(node->right, data);
        if (getBalanceFactor(node) > 1)
        {
            if (getNodeHeight(node->left->right) <= getNodeHeight(node->left->left))
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }
    if (data == node->data)
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }
        Node *temp = getMin(node->right);
        node->data = temp->data;
        node->right = removeNode(node->right, temp->data);
        if (getBalanceFactor(node) > 1)
        {
            if (getNodeHeight(node->left->right) <= getNodeHeight(node->left->left))
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }
    return node;
}

void removeAVLBinarySearchTree(AVLBinarySearchTree *tree, int data)
{
    tree->root = removeNode(tree->root, data);
}

void inOrderTraversal(Node *node)
{
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

void inOrderTraversalAVLBinarySearchTree(AVLBinarySearchTree *tree)
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

void postOrderTraversalAVLBinarySearchTree(AVLBinarySearchTree *tree)
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

void preOrderTraversalAVLBinarySearchTree(AVLBinarySearchTree *tree)
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

int heightAVLBinarySearchTree(AVLBinarySearchTree *tree)
{
    return height(tree->root);
}
