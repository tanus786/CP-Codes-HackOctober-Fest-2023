import java.util.Arrays;

class Solution {
    public int minDistance(String word1, String word2) {
        // Initialize a 2D array for memoization, where dp[i][j] represents
        // the minimum edit distance between word1[0...i] and word2[0...j].
        int[][] dp = new int[word1.length()][word2.length()];
        
        // Initialize the memoization array with -1 to indicate that
        // values have not been computed yet.
        for (int[] rows : dp) {
            Arrays.fill(rows, -1);
        }
        
        // Call the recursive function to calculate the minimum edit distance.
        return minDistance(0, 0, word1, word2, dp);
    }

    public int minDistance(int ind1, int ind2, String word1, String word2, int[][] dp) {
        // If we have reached the end of word1, we need to insert the remaining characters
        // from word2 into word1 to match them, so return the remaining length of word2.
        if (ind1 > word1.length() - 1) {
            return word2.length() - ind2;
        }

        // If we have reached the end of word2, we need to delete the remaining characters
        // from word1 to match them with word2, so return the remaining length of word1.
        if (ind2 > word2.length() - 1) {
            return word1.length() - ind1;
        }

        // If the current characters in word1 and word2 match, no operation is needed.
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        // If the current characters do not match, we have three options:
        // 1. Delete a character from word1 (ind1+1, ind2).
        // 2. Replace a character in word1 with the character from word2 (ind1+1, ind2+1).
        // 3. Insert a character from word2 into word1 (ind1, ind2+1).
        int a = 1 + minDistance(ind1 + 1, ind2, word1, word2, dp);
        int b = 1 + minDistance(ind1 + 1, ind2 + 1, word1, word2, dp);
        int c = 1 + minDistance(ind1, ind2 + 1, word1, word2, dp);

        // Return the minimum of the three options as the result and store it in dp.
        dp[ind1][ind2] = Math.min(a, Math.min(b, c));
        return dp[ind1][ind2];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String word1 = "horse";
        String word2 = "ros";
        int result = solution.minDistance(word1, word2);
        System.out.println("Minimum Edit Distance: " + result);
    }
}
