/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes)
{
    // Sort intervals based on start value
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    // Allocate memory for result
    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int index = 0;

    result[0] = (int *)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++)
    {
        if (result[index][1] >= intervals[i][0])
        {
            if (result[index][1] < intervals[i][1])
                result[index][1] = intervals[i][1];
        }
        else
        {
            index++;
            result[index] = (int *)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;
    return result;
}