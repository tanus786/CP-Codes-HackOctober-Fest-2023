class Solution:
    def maxIndexDiff(self, arr, n):
        leftMin = [0] * n
        rightMax = [0] * n

        leftMin[0] = arr[0]
        for i in range(1, n):
            leftMin[i] = min(arr[i], leftMin[i-1])

        rightMax[n-1] = arr[n-1]
        for i in range(n-2, -1, -1):
            rightMax[i] = max(arr[i], rightMax[i+1])

        maxDiff = 0
        i = 0
        j = 0
        while i < n and j < n:
            if leftMin[i] <= rightMax[j]:
                maxDiff = max(maxDiff, j - i)
                j += 1
            else:
                i += 1

        return maxDiff
