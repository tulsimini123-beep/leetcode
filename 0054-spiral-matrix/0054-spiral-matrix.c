#include <stdlib.h>

/**
 * Return an array of integers.
 * The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int m = matrixSize;
    int n = matrixColSize[0];

    int* result = (int*)malloc(m * n * sizeof(int));

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    int index = 0;

    while (top <= bottom && left <= right) {

        // 1. Left -> Right
        for (int col = left; col <= right; col++) {
            result[index++] = matrix[top][col];
        }
        top++;

        // 2. Top -> Bottom
        for (int row = top; row <= bottom; row++) {
            result[index++] = matrix[row][right];
        }
        right--;

        // 3. Right -> Left
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[index++] = matrix[bottom][col];
            }
            bottom--;
        }

        // 4. Bottom -> Top
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[index++] = matrix[row][left];
            }
            left++;
        }
    }

    *returnSize = index;

    return result;
}
