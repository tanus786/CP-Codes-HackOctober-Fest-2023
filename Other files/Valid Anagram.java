class Solution {
    public boolean isAnagram(String s, String t) {
        

        int sl = s.length();
        int tl = t.length();
        if(sl != tl){
            return false;
        }
        
        char a[] = s.toCharArray();
        Arrays.sort(a);
        char b[]  = t.toCharArray();
        Arrays.sort(b);
        String s1 = new String(a);
        String s2 = new String(b);
        return s1.equals(s2);
        
    }
}
