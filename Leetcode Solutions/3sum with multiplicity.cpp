int mod=1000000007;
class Solution {

// My solution :-    

    int bin(long long a,int b){
        long long tem=1;
        while(b){
            if(b&1){
                tem=(tem*a)%mod;
            }
            a=(a*a)%mod;
            b>>=1;
        }
        return (int)tem;
    }
    
    int fac(int x,int y){
        long long t=1,s=1;
        for(int i=0;i<y;i++){
            t=(t*(x-i))%mod;
        }
        for(int i=1;i<=y;i++){
            s=(s*i)%mod;
        }
        t=(t*bin(s,mod-2))%mod;
        return (int)t;
    }
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans=0,n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>un;
        for(auto i:arr)un[i]++;
        int i=0;
        while(i<n)
        {
            int tem=target-arr[i];
            unordered_map<int,int>m;
            m[arr[i]]++;
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]==tem){
                    m[arr[l]]++;
                    m[arr[r]]++;
                    long long res=1;
                    for(auto it:m){
                        res=((fac(un[it.first],it.second)%mod)*res)%mod;
                    }
                    ans=(ans+res)%mod;
                    m[arr[l]]--;m[arr[r]]--;
                    int lef=arr[l],rig=arr[r];
                    while(l<n && lef==arr[l])l++;
                    while(r>=0 && rig==arr[r])r--;
                }
                else if(arr[l]+arr[r]<tem)l++;
                else r--;
            }
            int cur=arr[i];
            while(i<n && arr[i]==cur)i++;
            
        }
        return (int)ans;
    }
    
    
//          Easy Solution
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int,int>m;
        int ans=0,n=arr.size();
        
        for(int i=0;i<n;i++){
            ans=(ans+m[target-arr[i]])%mod;
            for(int j=0;j<i;j++)m[arr[i]+arr[j]]++;
        }
        return ans;
    }
};
