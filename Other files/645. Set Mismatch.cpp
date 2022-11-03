class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = size(nums);
        unordered_map<int,int>freq;
        for (int num : nums) ++freq[num];
        int dup = -1;
        int miss = -1;
        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 2) {
                dup = i;
            } else if (freq[i] == 0) {
                miss = i;
            }
        }
        return {dup, miss};
    }
};
