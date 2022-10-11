#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) { 
        
        int numD[s.size()+1];        
        
        numD[0] = 1; // if(s.size() == 0) return 1;
        if(s[0] == '0') numD[1] = 0;
        else numD[1] = 1;
        
        for(int i = 2; i <= s.size(); i++) {
            if(s[i-1] == '0'){
                if(s[i-2] == '1' || s[i-2] == '2'){
                    numD[i] = numD[i-2];
                }
                else {
                    numD[i] = 0;
                }
            }
            else{            
                if(((s[i-2]-'0')*10 + (s[i-1] - '0') < 27) && s[i-2] != '0'){
                    numD[i] = (numD[i-1] + numD[i-2]);   
                } 
                else{
                    numD[i] = numD[i-1];
                }
            }                
        }
        
        return numD[s.size()];
    }