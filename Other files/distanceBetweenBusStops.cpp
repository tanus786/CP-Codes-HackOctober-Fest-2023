class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s=0,sum=0;
        for(auto i:distance)
            sum+=i;
        int i=start;
        while(i!=destination)
        {
            s+=distance[i];
            i = (i+1)%distance.size();
        }
        return min(s,sum -s);
    }
};
