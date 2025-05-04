#include <limits.h>
#include <stdio.h>
#define V 5
int findminDistance(int dist[], int included[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (included[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
}
void DijkstrasAlgo(int graph[V][V], int src) {
    int dist[V];
    int included[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        included[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = findminDistance(dist, included);
        included[u] = 1;
        for (int v = 0; v < V; v++) if (!included[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])  dist[v] = dist[u] + graph[u][v]; 
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        { 0, 1, 4, 6, 1 }, // Node A (0) connections
        { 1, 0, 0, 2, 0 }, // Node B (1) connections
        { 4, 0, 0, 0, 1 }, // Node C (2) connections
        { 6, 2, 0, 0, 5 }, // Node D (3) connections
        { 1, 0, 1, 5, 0 } // Node E (4) connections
    };
    DijkstrasAlgo(graph, 0);
    return 0;
}