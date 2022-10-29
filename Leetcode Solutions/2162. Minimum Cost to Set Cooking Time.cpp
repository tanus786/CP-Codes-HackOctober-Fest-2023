/*
The approach for this question is to generate all representations for the time and find the minimum cost.

Firstly, we convert the time as follows:

seconds = targetSeconds%60;
minutes = targetSeconds/60;
This method always gives us seconds < 60.

Edge Case:

When we have minutes = 100, i.e, targetSeconds >= 6000.
Since, we can only represent 99 as max value for minutes, Here, we are forced to use 100 as 99 and add 60 seconds to seconds part ( This is the reason why targetSeconds <= 6039 is a constraint as max time is 9999 ).
We can observe that since 1 minute can be subtracted and 60 seconds can be added to seconds part gives us at most two representations of targetSeconds possible.

The situation where two types of representations are possible:

Here, second representation is possible when we reduce minutes by 1 and add the same 60 seconds to the seconds part. Hence,

CONDITION:

minutes >=1  AND seconds <= 39  AND  minutes<100
Here, minutes>=1 as minutes-1 cannot be negative and adding 60 seconds to seconds part should be <=99. Hence, seconds <= 39 as seconds + 60 <= 99. minutes=100 are the edge cases handled seperately.

NOTE:

In this question we should only consider combinations with no leading zeroes as input in the string such as "960" will only be considered and "0960" will not be considered. The latter will require pushing an extra button which increses the cost, so it will give higher cost.

CODE:
*/
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        
        int secs = targetSeconds%60;
        int mins = targetSeconds/60;
        
        string type1="", type2="";
        
        // If mins is 0 then we won't take any string from mins 
        // as it only increases push cost
        if(mins==0) type1 = to_string(secs);

        // If mins < 100  we convert into normal time format
        else if(mins<100){
            type1 = to_string(mins);
            if(secs<=9) type1 += "0";
            type1 += to_string(secs);
        }

        // If min=100 we have to represent it as 99:xy format
        else{
            type1 = "99";
            type1 += to_string(secs + 60);
        }
             
        // Condition where two types can be present   
        if(mins>=1 && mins<100 && secs<=39){
            if(mins-1==0) type2 = to_string(secs+60); //limiting leading zeroes
            else{
                type2 = to_string(mins-1);
                type2 += to_string(secs+60);
            }
        }
        
        
        int i = 1;
        vector<string>arr;
        arr.push_back(type1);   
        // If type2 is there push in array 
        if(type2.size() > 0){ 
            arr.push_back(type2);
            i++;
        }

        int mini = INT_MAX;
        int totalCost = 0;
        
        while(i--){
            
            int n = arr[i][0]-'0';
            totalCost = pushCost;
            if(startAt != n) totalCost += moveCost;
            
            int j = 1;
            
            while(j < arr[i].size() ){
                if(arr[i][j] != arr[i][j-1]) totalCost += moveCost;
                totalCost += pushCost;
                j++;
            }
            
            mini = min(totalCost, mini);
        }
        
        return mini;
    }
};

// Hope you liked the explanation!!

// Thanks for reading!!
