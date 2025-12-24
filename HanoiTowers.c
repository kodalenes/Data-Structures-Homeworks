#include <stdio.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - hanoi(): O(2^n) - exponential time complexity
 *   - T(n) = 2*T(n-1) + 1
 *   - Solves to O(2^n)
 *   - Makes exactly 2^n - 1 moves for n disks
 * 
 * SPACE COMPLEXITY: O(n) - recursion stack depth
 *   - Maximum depth of recursion is n
 */

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1: %c -> %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);
    
    printf("Move disk %d: %c -> %c\n", n, from, to);
    
    hanoi(n - 1, aux, to, from);
}

int main() {
    int disks = 3;

    hanoi(disks, 'A', 'C', 'B');

    return 0;
}