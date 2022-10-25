class Sum {
    public static int maximum(int[] a) {
        int n = a.length;
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i <n ; i++) {
            int current = 0;
            for (int j = i; j < n; j++) {
             current = current + a[j];
            if (current > maxSum) {
                maxSum = current;
            }
            }
        }
        return maxSum;
    }
    public static void main(String args[]) {
        // Your code goes here
        int a[] = {1, 3, 8, -2, 6, -8, 5};
        System.out.println(maximum(a));
    }
}
