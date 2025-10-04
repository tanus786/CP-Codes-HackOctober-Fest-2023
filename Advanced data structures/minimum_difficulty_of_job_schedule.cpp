int minDifficulty(vector<int> &A, int D)
{
    int n = A.size();
    if (n < D)
        return -1;
    vector<int> dp(n, 1000), dp2(n), stack;
    for (int d = 0; d < D; ++d)
    {
        stack.clear();
        for (int i = d; i < n; i++)
        {
            dp2[i] = i ? dp[i - 1] + A[i] : A[i];
            while (stack.size() && A[stack.back()] <= A[i])
            {
                int j = stack.back();
                stack.pop_back();
                dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
            }
            if (stack.size())
            {
                dp2[i] = min(dp2[i], dp2[stack.back()]);
            }
            stack.push_back(i);
        }
        swap(dp, dp2);
    }
    return dp[n - 1];
}
