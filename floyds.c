#include <stdio.h>
#include <limits.h>


int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int n, int a[][100], int d[][100]) {
    int i, j, k;


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d[i][j] = a[i][j];
        }
    }


    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void printMatrix(int n, int d[][100]) {
    printf("Distance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, a[100][100], d[100][100];

    printf("Enter the number of vertices (n <= 100): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the weighted graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i != j && a[i][j] == 0) {
                a[i][j] = INT_MAX;
            }
        }
    }

    floyd(n, a, d);
    printMatrix(n, d);

    return 0;
}
