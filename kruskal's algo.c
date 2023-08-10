#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

int find(int vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = find(parent[vertex]);
    return parent[vertex];
}

void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(int numVertices, int graph[][MAX_VERTICES]) {
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    int mstEdges = 0;

    while (mstEdges < numVertices - 1) {
        int minWeight = __INT_MAX__;
        int minSrc = -1, minDst = -1;

        for (int src = 0; src < numVertices; src++) {
            for (int dst = 0; dst < numVertices; dst++) {
                if (graph[src][dst] != 0 && find(src) != find(dst) && graph[src][dst] < minWeight) {
                    minWeight = graph[src][dst];
                    minSrc = src;
                    minDst = dst;
                }
            }
        }

        if (minSrc != -1 && minDst != -1) {
            printf("%d -- %d weight: %d\n", minSrc, minDst, minWeight);
            unionSets(minSrc, minDst);
            mstWeight += minWeight;
            mstEdges++;
        } else {
            break;
        }
    }

    printf("Minimum Spanning Tree Weight: %d\n", mstWeight);
}

int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weighted square matrix (0 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Minimum Spanning Tree:\n");
    kruskalMST(numVertices, graph);

    return 0;
}

