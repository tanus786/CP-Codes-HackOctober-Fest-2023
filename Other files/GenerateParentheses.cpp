class Solution
{
  public:
    void solve(int open, close, string s, vector<string>&ans)
    {
       if(open == 0 && close == 0)
       {
         ans.push_back(s);
         return;
       }
      
      if(open != 0)
      {
        string s1 = s;
        s1.push_back('(');
        solve(open-1,close,s1,ans);
      }
      
      if(close>open)
      {
        string s2 = s;
        s2.push_back(')');
        solve(open,close-1,s2,ans);
      }
      
    }
  
  vector<string>Parenthesis(int n)
  {
    vector<string>ans;
    int open = n, close = n;
    string s = "";
    solve(open,close,s,ans);
    return ans;
  }
};
