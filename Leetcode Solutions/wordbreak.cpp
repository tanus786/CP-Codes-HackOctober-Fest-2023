class Solution {
public:
    
    // declare a dp

    int dp[305];

    unordered_set<string> s;

    bool helper(string& str, int i, int n)
    {
        // base case
        
        if(i == n)
        {
            return true;
        }
        
        // if already calculated

        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        // partition str at j and if substring is present int set then call for remaining part 

        for(int j = i; j < n; j++)
        {
            if(s.count(str.substr(i, j - i + 1)))
            {
                if(helper(str, j + 1, n))
                {
                    return dp[i] = true;
                }
            }
        }
        
        // store the res and return

        return dp[i] = false;
    }
    
    bool wordBreak(string str, vector<string>& wordDict) {

        int n = str.size();
        
        // insert all the words into set

        for(auto word : wordDict)
        {
            s.insert(word);
        }
        
        // declare dp with -1

        memset(dp, -1, sizeof(dp));

        return helper(str, 0, n);
    }
};
