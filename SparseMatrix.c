#include <stdio.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - convertToSparse(): O(r × c) where r is rows and c is columns
 *   - Must examine every element in the matrix
 * - Printing sparse matrix: O(k) where k is number of non-zero elements
 * 
 * SPACE COMPLEXITY:
 * - Sparse array: O(k) where k is non-zero elements
 *   - Only stores non-zero values with their positions
 *   - Much more efficient than O(r × c) for sparse matrices
 */

#define MAX 10

void convertToSparse(int matrix[MAX][MAX], int r, int c) {
    int sparse[MAX * MAX][3];
    int k = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = k - 1;

    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int r = 4, c = 4;
    int matrix[MAX][MAX] = {
        {0, 0, 3, 0},
        {0, 9, 0, 0},
        {0, 0, 0, 7},
        {1, 0, 0, 0}
    };

    convertToSparse(matrix, r, c);

    return 0;
}