class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
          int s=0,f=1;
          while(f<nums.size())
           {
               if(nums[s]!=nums[f])
               {
                   s++;
                   nums[s]=nums[f];
               }
             f+=1;
           }
       return s+1;
    }
};
