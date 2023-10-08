class Solution:
    def power(self, N, R):
        # Initialize the result to 1
        result = 1

        # Iterate over each bit of R
        while R > 0:
            # If the current bit of R is 1, multiply the result by N modulo (10**9+7)
            if R & 1:
                result = (result * N) % (10 ** 9 + 7)

            # Square N modulo (10**9+7) and halve R
            N = (N * N) % (10 ** 9 + 7)
            R >>= 1

        return result
