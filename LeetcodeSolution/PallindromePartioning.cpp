#define vvs vector<vector<string>>
class Solution
{
public:
    // Car A=B;
    // String x=S;//Copy Constructor
    bool isPalindrome(string &x)
    {
        int i = 0;
        int j = x.length() - 1;
        while (i < j)
        {
            if (x[i++] != x[j--])
                return false;
        }
        return true;
    }
    vvs ans;
    void solve(string &s, int i, vector<string> &temp)
    {
        if (i == s.length())
        {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < s.length(); ++j)
        {
            string x = s.substr(i, j - i + 1);
            if (isPalindrome(x))
            {
                temp.push_back(x);
                solve(s, j + 1, temp);
                temp.pop_back();
            }
        }
    }
    vvs partition(string &s)
    {
        vector<string> temp;
        solve(s, 0, temp);
        return ans;
    }
};