class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {

        int N = nums.size();
        vector<int> decreasing(N, 1), increasing(N, 1);

        for (int i = 1; i < N; i++) {
            if (nums[i] <= nums[i - 1]) {
                decreasing[i] = 1 + decreasing[i - 1];
            }
        }

        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                increasing[i] = 1 + increasing[i + 1];
            }
        }

        vector<int> ans;

        for(int i = k; i < N - k; i++) {
            if (increasing[i + 1] >= k && decreasing[i - 1] >= k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
