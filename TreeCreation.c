#include <stdio.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - initializeTree(): O(n) - initializes all n positions
 * - setRoot(): O(1) - constant time
 * - setLeft()/setRight(): O(1) - direct array access
 * - printTree(): O(n) - prints all n positions
 * 
 * SPACE COMPLEXITY: O(n)
 *   - Array-based tree representation uses fixed O(n) space
 *   - Simple and efficient for complete/nearly complete trees
 *   - Can waste space for sparse trees
 */

#define MAX_NODES 15

char tree[MAX_NODES];

void initializeTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = '-';
    }
}

void setRoot(char key) {
    tree[0] = key;
}

void setLeft(char key, int parentIndex) {
    int leftChildIndex = (2 * parentIndex) + 1;
    if (tree[parentIndex] == '-' || leftChildIndex >= MAX_NODES) {
        return;
    }
    tree[leftChildIndex] = key;
}

void setRight(char key, int parentIndex) {
    int rightChildIndex = (2 * parentIndex) + 2;
    if (tree[parentIndex] == '-' || rightChildIndex >= MAX_NODES) {
        return;
    }
    tree[rightChildIndex] = key;
}

void printTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] != '-') {
            printf("%c ", tree[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    initializeTree();
    
    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);

    printTree();

    return 0;
}