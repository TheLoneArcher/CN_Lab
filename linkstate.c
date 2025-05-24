#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 10
int graph[MAX][MAX], dist[MAX], prev[MAX], visited[MAX], n;
void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n; count++) {
        int u = -1, min = INT_MAX;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min)
                min = dist[i], u = i;
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
    }
}
int getNextHop(int src, int dest) {
    int hop = dest;
    while (prev[hop] != -1 && prev[hop] != src)
        hop = prev[hop];
    return (prev[hop] == -1) ? -1 : hop;
}
void printTable(int src) {
    dijkstra(src);
    printf("\nRouting Table for Node %d:\nDest\tCost\tNext Hop\n", src);
    for (int i = 0; i < n; i++) {
        if (i != src)
            printf("%d\t%d\t%d\n", i, dist[i], getNextHop(src, i));
    }
}
int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else {
                printf("Cost from %d to %d (-1 for no link): ", i, j);
                int cost;
                scanf("%d", &cost);
                graph[i][j] = (cost == -1) ? INT_MAX : cost;
            }
        }
    for (int i = 0; i < n; i++) printTable(i);
    return 0;
}
