#include <stdio.h>
#define MAX_NODES 20
typedef struct {
    int distance[MAX_NODES], from[MAX_NODES];    
} RoutingNode;
int main() { 
    int costMatrix[MAX_NODES][MAX_NODES], nodes, i, j, k, update_count; 
    RoutingNode routingTable[MAX_NODES];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &nodes);
    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costMatrix[i][j]);
            if (i == j) costMatrix[i][j] = 0; 
            routingTable[i].distance[j] = costMatrix[i][j];
            routingTable[i].from[j] = j;
        }
    }
    do {
        update_count = 0; 
        for (i = 0; i < nodes; i++) { 
            for (j = 0; j < nodes; j++) { 
                for (k = 0; k < nodes; k++) { 
                    if (routingTable[i].distance[j] > costMatrix[i][k] + routingTable[k].distance[j]) {
                        routingTable[i].distance[j] = costMatrix[i][k] + routingTable[k].distance[j];
                        routingTable[i].from[j] = k; 
                        update_count++; 
                    }
                }
            }
        }
    } while (update_count != 0); 
    for (i = 0; i < nodes; i++) {
        printf("\n\nFor router %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n"); 
        for (j = 0; j < nodes; j++) printf("%d\t\t%d\t\t%d\n", j + 1, routingTable[i].from[j] + 1, routingTable[i].distance[j]);
    }
    printf("\n");
    return 0; 
}