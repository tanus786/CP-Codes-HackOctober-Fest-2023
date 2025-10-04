//Cpp program to check if given two strings are anagram or not.
#include <bits/stdc++.h>
using namespace std;

    bool isAnagram(string a, string b){
        unordered_map<char,int>mp;
        int n = a.size();
        int m = b.size();
        
        if(n!=m) return false;
        
        for(auto x : a) mp[x]++;
        for(auto x : b) mp[x]--;
        
        for(auto x: mp){
            if(x.second!=0) return false;
        }
        return true;
        
    }


int main() {
    string c = "abba";
    string d = "bbaa";
    
    if (isAnagram(c, d))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
 
    return 0;
    
    }
