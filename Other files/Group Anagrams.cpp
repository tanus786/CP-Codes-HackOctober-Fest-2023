class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(i);
        }
        vector<vector<string>>ans;
        map<string,vector<int>> :: iterator itr;
        // cout<<mp.size();
        for(itr = mp.begin(); itr!=mp.end(); itr++){
            vector<int> arr = itr->second;
            // cout<<arr.size()<<" ";
            vector<string>temp;
            for(int i=0;i<arr.size(); i++){
                temp.push_back(strs[arr[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
