#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* answer = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    // Step 1: Store the product of all elements to the left
    answer[0] = 1;

    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply by the product of all elements to the right
    int suffix = 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix = suffix * nums[i];
    }

    return answer;
}