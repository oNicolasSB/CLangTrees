#include <stdlib.h>
#include <stdio.h>
#include "binarySearchTree.c"

int main()
{
    int array[40];
    srand(77);

    BinarySearchTree *tree = createBinarySearchTree();

    for (int i = 0; i < 40; i++)
    {
        array[i] = rand() % 1001;

        insertBinarySearchTree(tree, array[i]);

        printf("%d\n", array[i]);
    }

    printf("Altura da arvore: %d\n", heightBinarySearchTree(tree));

    inOrderTraversalBinarySearchTree(tree);

    int items[4] = {35, 290, 5, 6};

    for (int i = 0; i < 4; i++)
    {
        Node *node = searchBinarySearchTree(tree, items[i]);
        if (node == NULL)
        {
            printf("\nElemento %d nao encontrado", items[i]);
        }
        else
        {
            printf("\nElemento %d encontrado", items[i]);
        }
    }

    Node *teste = getMinBinarySearchTree(tree);

    printf("\nMenor elemento da arvore: %d\nMaior elemento da arvore: %d\n", getMinBinarySearchTree(tree)->data, getMaxBinarySearchTree(tree)->data);

    printf("\nRemovendo o elemento 35 da arvore\n");
    removeBinarySearchTree(tree, 35);
    inOrderTraversalBinarySearchTree(tree);

    printf("\nRemovendo o elemento 290 da arvore\n");
    removeBinarySearchTree(tree, 290);
    inOrderTraversalBinarySearchTree(tree);

    printf("\nRemovendo o elemento 966 da arvore\n");
    removeBinarySearchTree(tree, 966);
    inOrderTraversalBinarySearchTree(tree);
}