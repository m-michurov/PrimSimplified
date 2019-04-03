#include "graph.h"


void FreeGraph(
        void * graph)
{
    if (graph == NULL)
        return;

    free(((Graph *)graph)->distance);
    free(((Graph *)graph)->processed);
    free(((Graph *)graph)->parent);
    free(((Graph *)graph)->adjacency_matrix);
    free(((Graph *)graph)->MST);

    free(graph);
}


Graph * InitGraph(
        unsigned int vertices,
        unsigned int edges)
{
    Graph * graph = (Graph *) malloc(sizeof(Graph));

    if (graph == NULL)
        return NULL;

    graph->distance = malloc(vertices * sizeof(unsigned int));
    graph->processed = calloc(vertices, sizeof(unsigned int));
    graph->parent = malloc(vertices * sizeof(short));
    graph->adjacency_matrix = (unsigned int *) malloc(vertices * (1 + vertices) / 2 * sizeof(unsigned int));
    graph->MST = calloc(vertices > 0 ? vertices - 1 : 0, sizeof(Edge));

    if ((graph->distance == NULL || graph->processed == NULL || graph->parent == NULL ||
        graph->adjacency_matrix == NULL || graph->MST == NULL) && vertices)
    {
        FreeGraph(graph);
        free(graph);
        return NULL;
    }

    memset(graph->adjacency_matrix, 0xFF, (size_t) vertices * (1 + vertices) / 2 * sizeof(unsigned int));
    memset(graph->parent, 0xFF, (size_t) vertices * sizeof(short));
    memset(graph->distance, 0xFF, (size_t) vertices * sizeof(unsigned int));


    graph->distance[0] = 0;
    graph->vertices = vertices;
    graph->edges = edges;
    graph->mst_size = 0;

    return graph;
}
