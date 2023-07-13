/*TOPOLOGICAL SORT*/

#include <stdio.h>

void dfs(int u, int n, int visited[], int adjMatrix[10][10], int t[], int *k) {
    int v;
    visited[u] = 1;
    for (v = 0; v < n; v++) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            dfs(v, n, visited, adjMatrix, t, k);
        }
    }
    t[(*k)++] = u;
}

void topologicalSort(int n, int adjMatrix[10][10]) {
    int visited[10] = {0};
    int t[10], k = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, visited, adjMatrix, t, &k);
        }
    }

    printf("Topological order: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", t[i] + 1);
    }
    printf("\n");
}

int main() {
    int i, j, adjMatrix[10][10], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    topologicalSort(n, adjMatrix);
     return 0;
}
