class Solution {
    public int[] twoSum(int[] numbers, int target) {
       int [] arr = new int[2];
        
        int start=0 ;
        int end = numbers.length-1;
        
        while(start<=end)
        {
            int val = numbers[start]+numbers[end];
            
            if (val>target)
                end--;
            
            else if (val<target)
                start++;
            
            else{
                arr[0]=start+1;
                arr[1]=end+1;
                break;
            }
            
        }
        return arr;
    }
}