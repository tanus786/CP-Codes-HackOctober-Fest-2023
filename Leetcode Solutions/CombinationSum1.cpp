//Problem Statement:- Given an array of distinct integers and a target, 
//you have to return the list of all unique combinations where the chosen numbers sum to target. 
//You may return the combinations in any order.
//The same number may be chosen from the given array an unlimited number of times. 
//Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
//Problem Link:- https://leetcode.com/problems/combination-sum/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
       
        
        int n,a;
        n=candidates.size();
        vector <int> seq;
        vector<vector<int>> ans;

        combination_Sum(0,n,0,target,candidates,seq, ans);
        
        return ans;
    }
    
     void combination_Sum(int i,int n,int sum,int target,vector<int> &a, vector<int> &seq, vector<vector<int>> &ans)
        {
            if(sum==target)
            {
                ans.push_back(seq);
                return ;
            }
            if(i==n || sum>target)
                return;

           
                seq.push_back(a[i]);
                sum+=a[i];
                combination_Sum(i,n,sum,target,a,seq,ans);


            seq.pop_back();
            sum-=a[i];
            combination_Sum(i+1,n,sum,target,a,seq,ans);
            

        }
        
};