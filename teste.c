#include <stdio.h>
#include <stdlib.h>
#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#define TRUE 1
#define FALSE 0


int main() {
    // Inicializa a API Graphviz
    GVC_t *gvc = gvContext();
    
    // Cria um novo grafo direcionado
    Agraph_t *g = agopen("g", Agdirected, NULL);

    // Adiciona nós e arestas
    Agnode_t *n1 = agnode(g, "n1", TRUE);
    Agnode_t *n2 = agnode(g, "n2", TRUE);
    Agedge_t *e = agedge(g, n1, n2, NULL, TRUE);

    // Renderiza o grafo em um arquivo de saída
    gvLayout(gvc, g, "dot");
    gvRenderFilename(gvc, g, "png", "output.png");

    // Libera os recursos
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
    
    return 0;
}
