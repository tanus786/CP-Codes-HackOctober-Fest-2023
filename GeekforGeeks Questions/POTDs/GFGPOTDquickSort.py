class Solution:
    # Function to sort a list using quick sort algorithm.
    def quickSort(self, arr, low, high):
        if low < high:
            # Partition the array
            pi = self.partition(arr, low, high)

            # Recursively sort the left and right partitions
            self.quickSort(arr, low, pi - 1)
            self.quickSort(arr, pi + 1, high)

    def partition(self, arr, low, high):
        # Choose the rightmost element as pivot
        pivot = arr[high]

        # Index of the smaller element
        i = low - 1

        for j in range(low, high):
            # If the current element is smaller than or equal to the pivot
            if arr[j] <= pivot:
                # Swap arr[i+1] and arr[j]
                i += 1
                arr[i], arr[j] = arr[j], arr[i]

        # Swap the pivot element with the element at index i+1
        arr[i + 1], arr[high] = arr[high], arr[i + 1]

        return i + 1
