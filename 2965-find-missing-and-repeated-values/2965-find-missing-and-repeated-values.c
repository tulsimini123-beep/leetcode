/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
  // Function to find the repeated and missing numbers
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize)
{
    int total = gridSize * gridSize;

    // Allocate memory for answer array
    int *ans = (int*)malloc(2 * sizeof(int));

    // Frequency array initialized with 0
    int *freq = (int*)calloc(total + 1, sizeof(int));

    // Count frequency of every number
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            freq[grid[i][j]]++;
        }
    }

    // Find repeated and missing numbers
    for (int i = 1; i <= total; i++)
    {
        if (freq[i] == 2)
            ans[0] = i;      // Repeated number

        if (freq[i] == 0)
            ans[1] = i;      // Missing number
    }

    free(freq);

    *returnSize = 2;
    return ans;
}
 