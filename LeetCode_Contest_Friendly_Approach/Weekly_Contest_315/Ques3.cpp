class Solution {
    bool isPossible(vector<int>&arr,int maxCandies,long long k){
        int n = arr.size();
        long long cnt = 0;
        for(int i = 0; i < n;i++){
                cnt += 1LL*(arr[i] / maxCandies);
        }
        // cout<<maxCandies<<endl;
        return cnt >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long lo = 1,hi = 0;
        for(int x : candies){
            hi += x;
        }
        if(hi < k)return 0;
        int ans = 0;
        while(lo <= hi){
            long long  mid = lo + (hi - lo)/2;
            bool flag = isPossible(candies,mid,k);
            if(flag == true){
                lo = mid + 1;
                if(mid > ans)ans = mid;
            }else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
