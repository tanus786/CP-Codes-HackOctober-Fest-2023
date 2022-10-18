class Solution {
public:
    int convertTime(string current, string correct) {
        int currMin = stoi(current.substr(0,2)) * 60 + (stoi(current.substr(3,2)));
        int corrMin = stoi(correct.substr(0,2)) * 60 + (stoi(correct.substr(3,2)));
        int diff = corrMin - currMin;
        int cnt = 0;
        if(diff == 0)return 0;
        while(diff != 0){
            if(diff >= 60){
                diff -= 60;
            }else if(diff >= 15){
                diff-=15;
            }else if(diff >= 5){
                diff -= 5;
            }else{
                diff -=1;
            }
            cnt++;
        }
        return cnt;
    }
};
