#include <stdio.h>

int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0]; // Initialize maxSum with the first element of the array
    int currentSum = arr[0]; // Initialize currentSum with the first element

    for (int i = 1; i < size; i++) {
        // Calculate the maximum of the current element and the sum of the current element and the previous subarray sum
        currentSum = (arr[i] > currentSum + arr[i]) ? arr[i] : currentSum + arr[i];
        
        // Update maxSum if the current subarray sum is greater
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, size);

    printf("Maximum subarray sum is: %d\n", maxSum);

    return 0;
}
