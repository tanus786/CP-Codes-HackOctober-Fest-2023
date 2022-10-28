class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int flag=1;
        int ans=0;
        while(flag){
            flag=0;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]=='0'&&s[i+1]=='1'){
                    s[i]='1';
                    s[i+1]='0';
                    i++;
                    flag=1;
                }
            }
            ans++;
        }
        return ans-1;
    }
};
