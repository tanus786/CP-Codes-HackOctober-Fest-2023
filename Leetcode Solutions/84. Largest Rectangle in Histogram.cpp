// Time : 326 ms
// Memory : 76.4 MB
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int left[n];
        int right[n];
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
                left[i]=0;
            }
            else{
                while(s.empty()!=true&&heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(i);
                    left[i]=0;
                }
                else{
                    left[i]=s.top()+1;
                    s.push(i);
                }
                
            }
        }
        stack<int> r;
        for(int i=n-1;i>=0;i--){
            if(r.empty()){
                r.push(i);
                right[i]=n-1;
            }
            else{
                while(r.empty()!=true&&heights[r.top()]>=heights[i]){
                    r.pop();
                }
                if(r.empty()){
                    r.push(i);
                    right[i]=n-1;
                }
                else{
                    right[i]=r.top()-1;
                    r.push(i);
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int look=heights[i];
            ans=max(ans,(right[i]-left[i]+1)*look);
            
        }
        return ans;
    }
};
