#include "graph.h"
#include <stdio.h>


static inline unsigned short closest_vertex(
        Graph * graph)
{
    unsigned short v = 0;

    unsigned int min_distance = UINT_MAX;

    for (unsigned short t = 0; t < graph->vertices; t++) {
        if (graph->distance[t] <= min_distance && graph->adjacency_matrix[offset(t, t)] != PROCESSED) {
            min_distance = graph->distance[t];
            v = t;
        }
    }

    return v;
}


int MakeMST(
        Graph * graph)
{
    if (graph == NULL)
	    return -1;

    unsigned short v = 0;

    if (graph->vertices && graph->edges)
    {
        for (unsigned int k = 0; k < graph->vertices; k++)
        {
            v = closest_vertex(graph);

            graph->adjacency_matrix[offset(v, v)] = PROCESSED;

            for (unsigned short u = 0; u < graph->vertices; u++)
            {
                if (graph->adjacency_matrix[offset(v, u)] != UINT_MAX
                    && graph->adjacency_matrix[offset(u, u)] != PROCESSED
                    && graph->adjacency_matrix[offset(v, u)] < graph->distance[u])
                {
                    graph->distance[u] = graph->adjacency_matrix[offset(v, u)];
                    graph->parent[u] = (short) v;
                }
            }

            if (graph->parent[v] != NO_PARENT) {
                graph->MST[graph->mst_size].src = (unsigned short) graph->parent[v];
                graph->MST[graph->mst_size].dst = v;
                graph->mst_size++;
            }
        }
    }

    if (graph->mst_size != graph->vertices - 1 || !graph->vertices) {
        return MST_ERROR;
    }

    return SUCCESS;
}
