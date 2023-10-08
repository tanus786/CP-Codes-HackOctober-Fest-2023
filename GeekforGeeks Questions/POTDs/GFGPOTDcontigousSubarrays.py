class Solution:
    def countSubArrayProductLessThanK(self, a, n, k):
        count = 0
        product = 1
        left = 0

        for right in range(n):
            product *= a[right]

            while product >= k and left <= right:
                product //= a[left]
                left += 1

            count += right - left + 1

        return count
