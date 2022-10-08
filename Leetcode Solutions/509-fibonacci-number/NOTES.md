memoization sol
```
class Solution {
public:
int fib(int n) {
vector<int> dp(n+1,0);
return fib(n,dp);
}
int fib(int n,vector<int> &dp){
if(n <= 1) return 1;
if(dp[n] != 0) return dp[n];
return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}
};
```
Tabulation with extra space
```
class Solution {
public:
int fib(int n) {
vector<int> dp(n,0);
if(dp.size() <= 0) return 0;
if(dp.size() == 1) return 1;
dp[0] = dp[1] = 1;
for(int i=2;i<dp.size();i++)
dp[i] = dp[i-1]+dp[i-2];
return dp[dp.size()-1];
}
};
```