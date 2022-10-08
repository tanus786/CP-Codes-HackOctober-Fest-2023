backtracking
​
```
class Solution { //need to change void to int
public:
void fn(int index,vector<int> &cost,int &curr,int &ans){ //backtracking
if(index >= cost.size()){
ans = min(ans,curr);
return;
}
curr += cost[index]; //do
fn(index+1,cost,curr,ans); //recur
fn(index+2,cost,curr,ans); //recur
curr -= cost[index]; //undo
}
int minCostClimbingStairs(vector<int>& cost) {
int ans1=INT_MAX,ans2=INT_MAX;
int curr1 = 0,curr2 = 0;
fn(0,cost,curr1,ans1);
fn(1,cost,curr2,ans2);
return min(ans1,ans2);
}
};
```