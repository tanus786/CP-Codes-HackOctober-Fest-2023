/* Author :  JaiSehgal007 */

/* MINIMUM WINDOW SUBSTRING */

/* Link to the Problem : https://leetcode.com/problems/decode-ways-ii/ */

/*

PROBLEM DESCRIPTION::

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

*/

/*

SOME PROBLEM RELATED EXAMPLE::

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/

/*-------------------------------------SOLUTION----------------------------------------------------*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        for(auto ch:t)freq[ch]++;
        int counter=t.size(),begin=0,end=0,d=INT_MAX,head=0;
        while(end<s.size()){
            if(freq[s[end++]]-->0)counter--;
            while(!counter){
                if(end-begin<d)d=end-(head=begin);
                if(freq[s[begin++]]++==0)counter++;
            }
        }
        if(d==INT_MAX)return "";
        return s.substr(head,d);
    }
};
