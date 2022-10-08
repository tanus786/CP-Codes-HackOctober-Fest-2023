class Solution {
public:
    /**
    * @author Anandha Krishnan VK
    * Time and Space = O(nm)
    * Method - Dynamic Programming
    */
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.length()+1,vector<int>(text1.length()+1,0));
        
        for(int i=1;i<text2.length()+1;i++){
            for(int j=1;j<text1.length()+1;j++){
                if(text2[i-1] == text1[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }  
        
        return dp[text2.length()][text1.length()];
    }
};