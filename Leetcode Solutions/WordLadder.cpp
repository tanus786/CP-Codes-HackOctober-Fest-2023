class Solution 
{
public:
    int ladderLength(string begin, string end, vector<string>& wordList) 
    {
        unordered_set<string> hs(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({begin, 1});
        while(!q.empty())
        {
            string s = q.front().first;
            int len = q.front().second;
            q.pop();
            if(s == end)
                return len;
            int n = s.length();
            for(int i=0; i<n; i++)
            {
                char org = s[i];
                for(int j=0; j<26; j++)
                {
                    s[i] = (char) ('a' + j);
                    if(hs.find(s) != hs.end())
                    {
                        hs.erase(s);
                        q.push({s, len+1});
                    }
                }
                s[i] = org;
            }
        }
        return 0;
    }
};
