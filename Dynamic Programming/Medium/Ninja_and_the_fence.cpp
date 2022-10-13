#include <bits/stdc++.h> 
#include<vector>
#define MOD 1000000007
int add(int a,int b){
    return (a%MOD + b%MOD) %MOD;
} 
int mult(int a,int b){
    return ((a%MOD) * 1LL * (b%MOD)) %MOD;
}

//approch-1 using recursion + memoization
int solvemem(int n,int k,vector<int>&dp){
    if(n==1)
        return k;
    if(n==2)
        return add(k,mult(k,k-1));
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]= add(mult(solvemem(n-2,k,dp),k-1),mult(solvemem(n-1,k,dp),k-1));
    return dp[n];
    }


//approch-2 using botton-up approach
int solvetab(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=add(k,mult(k,k-1));
    
    for(int i=3;i<=n;i++){
        dp[i] = add(mult(dp[i-2],k-1),mult(dp[i-1],k-1));
    }
    return dp[n];
}

//approch-3 using space optimization method
int solve(int n,int k){
    int prev2 = k;
    int prev1 = add(k,mult(k,k-1));
    for(int i=3;i<=n;i++){
        int ans = add(mult(prev2,k-1),mult(prev1,k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
  //approach-1
    vector<int>dp(n+1,-1);
    return solvemem(n,k,dp);
  
  //approach-2
  return solvetab(n,k);
  
  //approach-3
  return solve(n,k);
}
