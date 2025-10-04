class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>vec;
        int maxv=*max_element(candies.begin(), candies.end());
        for (int ele:candies){
            if (ele+extraCandies>=maxv){
                vec.push_back(true);
            }
            else{
                vec.push_back(false);
            }
        }
        return vec;
    }
};
