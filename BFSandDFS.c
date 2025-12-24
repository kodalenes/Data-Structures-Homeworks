#include <stdio.h>
#include <stdbool.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - BFS: O(V + E) where V is vertices and E is edges
 *   - Each vertex is visited once: O(V)
 *   - Each edge is explored once: O(E)
 * - DFS: O(V + E) - same reasoning as BFS
 * - enqueue/dequeue: O(1) - constant time operations
 * 
 * SPACE COMPLEXITY:
 * - BFS: O(V) - queue can hold all vertices in worst case
 * - DFS: O(V) - recursion stack depth in worst case
 * - Adjacency Matrix: O(V²) - stores all possible edges
 */

#define MAX 10

int adjacencyMatrix[MAX][MAX];
bool visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void resetVisited() {
    for (int i = 0; i < MAX; i++) visited[i] = false;
}

void bfs(int startNode, int totalNodes) {
    resetVisited();
    enqueue(startNode);
    visited[startNode] = true;

    while (front <= rear && front != -1) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < totalNodes; i++) {
            if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

void dfs(int currentNode, int totalNodes) {
    printf("%d ", currentNode);
    visited[currentNode] = true;

    for (int i = 0; i < totalNodes; i++) {
        if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            dfs(i, totalNodes);
        }
    }
}

int main() {
    int nodes = 4;
    
    int edges[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            adjacencyMatrix[i][j] = edges[i][j];

    printf("BFS Traversal: ");
    bfs(0, nodes);

    printf("\nDFS Traversal: ");
    resetVisited();
    dfs(0, nodes);

    return 0;
}