class Solution
{
public:
int dp[1102];
      bool helper(int i,string s,set<string>st){
          if(i>=s.size())
            return true;
          if(dp[i]!=-1)
            return dp[i];
          string temp="";
           for(int j=i;j<s.length();j++){
                temp+=s[j];
               if(st.find(temp)!=st.end()){
                   if(helper(j+1,s,st))
                     return dp[i]=true;
            }
        }
        return dp[i]=false;
      }
    int wordBreak(string A, vector<string> &B) {
        //code here
        memset(dp,-1,sizeof(dp));
        set<string>s;
        for(int i=0;i<B.size();i++)
        s.insert(B[i]);//this is basically done so as to put only distvt eleemnts
        return helper(0,A,s);
    }
};