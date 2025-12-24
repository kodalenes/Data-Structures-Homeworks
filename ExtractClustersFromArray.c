#include <stdio.h>
#include <stdbool.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - traverseCluster(): O(V + E) where V is vertices and E is edges
 *   - DFS traversal visits each node and edge once
 * - findClusters(): O(V + E) for all clusters combined
 *   - Each node is visited exactly once across all DFS calls
 * 
 * SPACE COMPLEXITY:
 * - O(V) for visited array and recursion stack
 * - Adjacency matrix: O(V²)
 */

#define MAX 10

int adjacencyMatrix[MAX][MAX];
bool visited[MAX];

void traverseCluster(int node, int totalNodes) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < totalNodes; i++) {
        if (adjacencyMatrix[node][i] == 1 && !visited[i]) {
            traverseCluster(i, totalNodes);
        }
    }
}

void findClusters(int totalNodes) {
    int clusterID = 0;

    for (int i = 0; i < totalNodes; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < totalNodes; i++) {
        if (!visited[i]) {
            clusterID++;
            printf("Cluster %d: ", clusterID);
            traverseCluster(i, totalNodes);
            printf("\n");
        }
    }
}

int main() {
    int nodes = 6;
    int edges[6][6] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adjacencyMatrix[i][j] = edges[i][j];
        }
    }

    findClusters(nodes);

    return 0;
}