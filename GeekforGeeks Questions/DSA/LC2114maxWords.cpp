class Solution
{
    public:
        int mostWordsFound(vector<string> &sentences)
        {
            int maxi = 0;
            for (int j = 0; j < sentences.size(); j++)
            {
                string cand = sentences[j];
                int temp = 0;
                for (int i = 0; i < cand.length(); i++)
                {
                    if (cand[i] == ' ' && cand[i + 1] != ' ')
                        temp++;
                }
                maxi = max(maxi, temp);
            }
            return maxi + 1;
        }
};
