/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
       
        vector<int> freq(26,0);
        for(int i = 0 ; i < t.length(); i ++){
            
            freq[t[i]-'a']++;
        }
        for(int i = 0 ; i < s.length(); i ++){
            
            freq[s[i]-'a']--;
        }
        
        for(int i = 0 ; i < 26; i ++){
            
           if(freq[i]<0 || freq[i]>=1){
               return false;
           }
        }
        return true;
    }
};