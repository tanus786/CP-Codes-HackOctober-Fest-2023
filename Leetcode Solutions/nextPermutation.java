class Solution {
    public void nextPermutation(int[] nums) {
        int j=-1;
        for(int i=nums.length-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                j=i-1;
                break;
            }
        }
        if(j==-1)j=0;
        int toswap=-1;
        for(int i=j+1;i<nums.length;i++){
            if(nums[j]>=nums[i]){
                toswap=i-1;
                break;
            }
        }
        if(toswap==j || toswap==-1)toswap=nums.length-1;
        int temp=nums[j];
        nums[j]=nums[toswap];
        nums[toswap]=temp;
        Arrays.sort(nums,j+1,nums.length);
        
    }
}