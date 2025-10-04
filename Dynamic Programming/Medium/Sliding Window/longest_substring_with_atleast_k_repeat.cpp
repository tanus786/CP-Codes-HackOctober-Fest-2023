class Solution {
public:
    int longestSubstring(string s, int k) {
        //based on hahsing 
        //ie based on hashmap data structure
       //Naive approach for this question shall be to generate all the substring s
        //and then we basically find th ecount pf each and every character
        //optimised us to use a hashmap data structrue
        //hahsing + 2ptr approach
        int maxi=INT_MIN;
        int i=0,j=0;
        int n=s.size();
        unordered_map<char,int>ump;
        while(j<n){
            ump[s[j]]++;
            if(ump[s[j]]>=k){
                maxi=max(maxi,j-i);
            }
        }
    }
};