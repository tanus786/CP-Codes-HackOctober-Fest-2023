class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w=0;
        int b=0;
        int i=0;
        while(i<k){
            if(blocks[i]=='W')
                w++;
            else
                b++;
            i++;
        }
        int maxi=b;
        for(int j=0;i<blocks.size()&&j<blocks.size();i++,j++){
            if(blocks[j]=='B')
                b--;
            if(blocks[i]=='B')
                b++;
            maxi=max(b,maxi);
        }
        if(k-maxi<0)
            return 0;
        return k-maxi;
        
    }
};
