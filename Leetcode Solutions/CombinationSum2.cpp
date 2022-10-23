//Problem Statement:- Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
//Problem Link:- https://leetcode.com/problems/combination-sum-ii/



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int i,n;
        n=candidates.size();
	   
        vector <int> seq;
        vector<vector<int>> v;

        // Sort the array in the start to get the desired output
        sort(candidates.begin(),candidates.end());

        combinationSum(0,n,0,target,candidates,seq,v);
        
        return v;
    }
    
    
    void combinationSum(int i,int n,int sum,int target, vector<int> &a, vector<int> &seq, vector <vector<int>> &v)
    {
        //Base condition, If target reached, add it to our vector v , which is the answer
        if(sum==target)
        {
            v.push_back(seq);
            return;
        }
        if(i==n || sum>target)
            return;

            else
            {
                for(int j=i;j<n;j++)
                {
                    if(j!=i && a[j]==a[j-1])
                        continue;
                    else
                    {
                          //Include an element & see if target can be reached by it's sequences.
                          seq.push_back(a[j]);
                          combinationSum(j+1,n,sum+a[j],target,a,seq,v);

                          //Exclude an element & see if target can be reached by it's sequences.
                          seq.pop_back();
                      }
                }
               

                
            }


}
};