#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>
// #include <graphviz/xdot.h>
#include "autoBalancedBinarySearchTree.c"

void preOrderTraversalGraph(Node *node, Agraph_t *g)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    char nodeName[15];
    snprintf(nodeName, sizeof(nodeName), "%d", node->data);
    Agnode_t *agNode = agnode(g, nodeName, 1);

    if (node->left)
    {
        char leftNodeName[15];
        snprintf(leftNodeName, sizeof(leftNodeName), "%d", node->left->data);
        Agnode_t *leftNode = agnode(g, leftNodeName, 1);
        agedge(g, agNode, leftNode, NULL, 1);
        preOrderTraversalGraph(node->left, g);
    }
    if (node->right)
    {
        char rightNodeName[15];
        snprintf(rightNodeName, sizeof(rightNodeName), "%d", node->right->data);
        Agnode_t *rightNode = agnode(g, rightNodeName, 1);
        agedge(g, agNode, rightNode, NULL, 1);
        preOrderTraversalGraph(node->right, g);
    }
}

void preOrderTraversalGraphAVLBinarySearchTree(AVLBinarySearchTree *tree, Agraph_t *g)
{
    preOrderTraversalGraph(tree->root, g);
}

void makeViz(AVLBinarySearchTree *tree, const char *name)
{
    GVC_t *gvc = gvContext();
    Agraph_t *g = agopen("g", Agdirected, NULL);

    preOrderTraversalGraphAVLBinarySearchTree(tree, g);

    gvLayout(gvc, g, "dot");
    gvRenderFilename(gvc, g, "png", "outputAVL.png");

    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}

int main()
{
    int array[40];
    srand(77);

    AVLBinarySearchTree *tree = createAVLBinarySearchTree();

    for (int i = 0; i < 40; i++)
    {
        array[i] = rand() % 1001;

        insertAVLBinarySearchTree(tree, array[i]);

        printf("%d\n", array[i]);
    }
    // Node *teste = searchAVLBinarySearchTree(tree, 899);

    removeAVLBinarySearchTree(tree, 451);
    removeAVLBinarySearchTree(tree, 934);
    removeAVLBinarySearchTree(tree, 973);
    removeAVLBinarySearchTree(tree, 989);
    removeAVLBinarySearchTree(tree, 895);
    removeAVLBinarySearchTree(tree, 885);
    makeViz(tree, "tree");
    return 0;
}