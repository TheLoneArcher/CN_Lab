#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_NODES 10
typedef struct {
    int cost[MAX_NODES], nextHop[MAX_NODES];
    bool visited;
} Node;
void initializeNode(Node *node, int nodeCount, int source) {
    for (int i = 0; i < nodeCount; i++) {
        node->cost[i] = (i == source) ? 0 : INT_MAX;
        node->nextHop[i] = (i == source) ? source : -1;
    }
    node->visited = false;
}
int findMinCostNode(Node network[], int nodeCount) {
    int minCost = INT_MAX, minIndex = -1;
    for (int i = 0; i < nodeCount; i++) {
        if (!network[i].visited && network[i].cost[i] < minCost) {
            minCost = network[i].cost[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void updateCosts(Node network[], int u, int nodeCount) {
    for (int v = 0; v < nodeCount; v++) {
        if (!network[v].visited && network[u].cost[v] != INT_MAX) {
            int newCost = network[u].cost[u] + network[u].cost[v];
            if (newCost < network[v].cost[v]) {
                network[v].cost[v] = newCost;
                network[v].nextHop[v] = u;
            }
        }
    }
}
void linkStateRouting(Node network[], int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        int u = findMinCostNode(network, nodeCount);
        if (u == -1) break;
        network[u].visited = true;
        updateCosts(network, u, nodeCount);
    }
}
void displayTable(Node *node, int source, int nodeCount) {
    printf("Routing Table for Node %d:\n", source);
    printf("Dest\tCost\tNext Hop\n");
    for (int dest = 0; dest < nodeCount; dest++) if (dest != source) printf("%d\t%d\t%d\n", dest, node->cost[dest], node->nextHop[dest]);
    printf("\n");
}
int main() {
    int nodeCount;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    Node network[MAX_NODES];
    for (int i = 0; i < nodeCount; i++) initializeNode(&network[i], nodeCount, i);
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            if (i != j) {
                printf("Cost from %d to %d (-1 for no link): ", i, j);
                int cost;
                scanf("%d", &cost);
                network[i].cost[j] = (cost == -1) ? INT_MAX : cost;
            }
        }
    }
    linkStateRouting(network, nodeCount);
    for (int i = 0; i < nodeCount; i++) displayTable(&network[i], i, nodeCount);
    return 0;
}