class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp1,mp2;
        
        for(auto &it : matches){
            mp1[it[0]]++;
            mp2[it[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto &it : mp1){
            if(mp2.count(it.first) == 0){
                ans[0].push_back(it.first);
            }
        }
        for(auto &it : mp2){
            if(it.second == 1){
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};
