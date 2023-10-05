package CSESProblemSet.DynamicProgramming;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class LIS {
    public static List<Integer> divisibleSet(int[] arr) {
        int n = arr.length;

        int dp[] = new int[n];
        int hash[] = new int[n];

        Arrays.fill(dp, 1);
        Arrays.sort(arr);
        int maxi = 1;
        int last_idx = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // store the prev index
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last_idx = i;
            }

        }
        ArrayList<Integer> lis = new ArrayList<Integer>();
        lis.add(arr[last_idx]);
        while (hash[last_idx] != last_idx) {
            last_idx = hash[last_idx];
            lis.add(arr[last_idx]);
        }

        Collections.reverse(lis);
        return lis;

    }

    // public static int LIS(int arr[]) {
    // int n = arr.length;

    // int dp[][] = new int[n][n + 1];

    // for (int i = n - 1; i >= 0; i--) {
    // for (int prev = i - 1; prev >= -1; prev--) {

    // int len = dp[i + 1][prev + 1];

    // if (prev == -1 || arr[i] > arr[prev]) {
    // len = Math.max(len, 1 + dp[i + 1][i + 1]);
    // }
    // dp[i][prev + 1] = len;
    // }
    // }

    // return dp[0][-1 + 1];
    // }

    // to trace back the LIS
    public static int LIS(int arr[]) {
        int n = arr.length;

        int dp[] = new int[n];
        int hash[] = new int[n];

        Arrays.fill(dp, 1);

        int maxi = 1;
        int last_idx = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // store the prev index
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last_idx = i;
            }

        }
        ArrayList<Integer> lis = new ArrayList<Integer>();
        lis.add(arr[last_idx]);
        while (hash[last_idx] != last_idx) {
            last_idx = hash[last_idx];
            lis.add(arr[last_idx]);
        }

        Collections.reverse(lis);
        return maxi;

    }

    public static int longestIncreasingSubsequence(int[] arr, int n) {
        List<Integer> temp = new ArrayList<>();
        temp.add(arr[0]);

        int len = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.get(temp.size() - 1)) {
                // arr[i] > the last element of temp array
                temp.add(arr[i]);
                len++;
            } else {
                // Replacement step
                int ind = Collections.binarySearch(temp, arr[i]);
                if (ind < 0) {
                    ind = -(ind + 1);
                }
                temp.set(ind, arr[i]);
            }
        }

        return len;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String line[] = br.readLine().split("\\s+");

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]);
        }

        System.out.println(longestIncreasingSubsequence(arr, n));

    }
}