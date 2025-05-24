#include <stdio.h>
#define MAX_NODES 20
typedef struct {
    int distance[MAX_NODES], from[MAX_NODES];    
} RoutingNode; // each node has a distance array which stores the distance of each node from the source node and a from array which stores the next hop to reach that node
int main() { 
    int costMatrix[MAX_NODES][MAX_NODES], nodes, i, j, k, update_count; 
    RoutingNode routingTable[MAX_NODES];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &nodes); // get the number of nodes from the user
    printf("\nEnter the cost matrix:\n"); // get the cost matrix from the user 
    for (i = 0; i < nodes; i++) { 
        for (j = 0; j < nodes; j++) { 
            scanf("%d", &costMatrix[i][j]); // for the cost matrix
            if (i == j) costMatrix[i][j] = 0; // distance from a node to itself is 0
            routingTable[i].distance[j] = costMatrix[i][j]; // initialize the distance array with cost matrix
            routingTable[i].from[j] = j; // also initialize the from array with the node number
        }
    }
    do {
        update_count = 0; // the update count is used to check if the routing table has been updated or not, if it's not updated then the routing table has converged and the algorithm can stop
        for (i = 0; i < nodes; i++) { 
            for (j = 0; j < nodes; j++) { 
                for (k = 0; k < nodes; k++) { // check if the distance from i to j is greater than the distance from i to intermediary node k plus the distance from k to j
                    if (routingTable[i].distance[j] > costMatrix[i][k] + routingTable[k].distance[j]) {
                        routingTable[i].distance[j] = costMatrix[i][k] + routingTable[k].distance[j];
                        routingTable[i].from[j] = k; // update the next hop to reach j from i 
                        update_count++;  // update the update count
                    }
                }
            }
        }
    } while (update_count != 0); // stop when routing table has converged
    for (i = 0; i < nodes; i++) { // print the routing table
        printf("\n\nFor router %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n"); 
        for (j = 0; j < nodes; j++) printf("%d\t\t%d\t\t%d\n", j + 1, routingTable[i].from[j] + 1, routingTable[i].distance[j]);
    }
    printf("\n");
    return 0; 
}