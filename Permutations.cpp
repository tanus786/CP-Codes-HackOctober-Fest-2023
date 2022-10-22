class Solution {
public:
    void permutation(vector<int> &vec, int k, vector<int> &a, vector<int> &res, vector<vector<int>> &ans){
        if(k==vec.size()){
            ans.push_back(res);//pushing res vector to ans vector
        }
        else{
            for(int i=0;i<vec.size();i++){
			//checking if that element is already taken or not, if it is 0 then we will add it
			//in resultant vector else we will move forward
                if(a[i]==0){
                    res[k] = vec[i];  //adding element to resultant vector
                    a[i] = 1;  //Assign 1 such that next time it will not get counted
                    permutation(vec, k+1, a, res, ans);  //calling function by increasing k
                    a[i] = 0;  //backtracking(moving back to previous position)
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> a(nums.size(), 0);  //for storing 0 & 1(vector for checking)
        vector<int> res(nums.size());  //for storing vector elemets
        permutation(nums, 0, a, res, ans);  //calling recursive function
        return ans;  //returning answer
    }
};
