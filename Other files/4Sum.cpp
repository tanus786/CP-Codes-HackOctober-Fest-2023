class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        //start & end pointers
        int s, e;
        //initializing answer vector
        vector<vector<int>> ans;
        //initializing set
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        
        //Edge Case
        if(n < 4){
            return ans;
        }
        
        // fixing first element of quadruplets 
        for(int i = 0; i < n; i++){
            // fixing second element of quadruplets 
            for(int j = i+1; j < n; j++){
                // now we are left with 2SUM problem
                //intializing start and end
                s = j + 1;
                e = n - 1;
                
                while(s < e){
                    
                    if((long) nums[i] + nums[j] + nums[s] + nums[e] == target){
                        st.insert({nums[i], nums[j], nums[s], nums[e]});
                        s++, e--;
                    }
                    else if((long) nums[i] + nums[j] + nums[s] + nums[e] > target){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        
        // storing elements of set into ans
        for(auto i: st)
            ans.push_back(i);
        
        return ans;
    }
};
