#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.c"

void main()
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->root = (Node *)malloc(sizeof(Node));
    Node *n1 = createNode('a');
    Node *n2 = createNode('+');
    Node *n3 = createNode('*');
    Node *n4 = createNode('b');
    Node *n5 = createNode('-');
    Node *n6 = createNode('/');
    Node *n7 = createNode('c');
    Node *n8 = createNode('d');
    Node *n9 = createNode('e');

    n6->left = n7;
    n6->right = n8;
    n5->left = n6;
    n5->right = n9;
    n3->left = n4;
    n3->right = n5;
    n2->left = n1;
    n2->right = n3;

    tree->root = n2;

    inOrderTraversalBinaryTree(tree);
    puts("");
    postOrderTraversalBinaryTree(tree);

    printf("\nAltura da arvore: %d\n", heightBinaryTree(tree));
    printf("\n d: %d", height(n8));

    return;
}