#include <limits.h>
#include <stdio.h>
#define V 5
#define INF INT_MAX
int findminDistance(int dist[], int included[]) { // take the distance arrany and included array to find minimum neighboring node
    int min = INF, min_index; // initialize min to infinity and declare min_index
    for (int v = 0; v < V; v++) {// iterate through the vertices
        if (included[v] == 0 && dist[v] <= min) { // if not included and the neighboring node's distance is less than min, update min
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void DijkstrasAlgo(int graph[V][V], int src) {
    int dist[V], included[V]; // declare distance and included arrays
    for (int i = 0; i < V; i++) { // initialize distance to infinity for all nodes and included to 0
        dist[i] = INF;
        included[i] = 0;
    }
    dist[src] = 0; // set the source node's distance to 0
    for (int count = 0; count < V - 1; count++) { // iterate through the vertices - 1 with a count variable, can be anything
        int u = findminDistance(dist, included); // find the nearest neithboring node
        included[u] = 1; // mark as visited
        for (int v = 0; v < V; v++) if (!included[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])  dist[v] = dist[u] + graph[u][v];  // for each vertex, if it's not included and there's a path and if the neighboring node's distance isn't infinity and the distance from source to neighboring node is less than distance of neighboring node, then update the neighoring node's distance
        // basically what this does is it declares an initialies distance and visited arrays, and then for each node whose distance is to be found (the first for loop), it finds the minimum distance and marks as included, then for each of the neighboring nodes of the minimum node, it checks if the neighboring node isn't visited, and there's a path to the node and the distance of u isn't infinity and that there's a shorter path for v from u and updates it
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]); // print the distance array as the answer!! that's it
}

int main() {
    int graph[V][V] = {
        { 0, 1, 4, 6, 1 }, 
        { 1, 0, 0, 2, 0 }, 
        { 4, 0, 0, 0, 1 }, 
        { 6, 2, 0, 0, 5 }, 
        { 1, 0, 1, 5, 0 } 
    };
    DijkstrasAlgo(graph, 0);
    return 0;
}