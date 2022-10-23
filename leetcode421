class Solution {
    public int findMaximumXOR(int[] nums) {

        int max = 0;
        int check = 0;
        int l = nums.length;
           for(int i = 31; i >= 0; i--){
            check = check | (1 << i);
            Set<Integer> set = new HashSet<>();
            List<Integer> list = new ArrayList<>();
            for(int j= 0; j<l; j++){
                set.add(nums[j] & check);
            }
            for(int x: set){
                list.add(x);
            }
            int now = max | (1 << i);
            int len = set.size();
            for(int q = 0; q<len; q++){
                if(set.contains(now ^ list.get(q))) {
                    max = now;
                    break;
                }
            }
        }
          System.out.println(max);
             return max;
    }
}
