class Solution {
public:
    string minWindow(string s, string t) {
        int beg =0,mn = INT_MAX;
        int c=0 , in=-1;
        int ns= s.length(),nt = t.length();
        unordered_map<char,int> m1,m2;
        int i;
        for( i=0;i<nt;i++)
            m1[t[i]]++;
        
        for(i=0;i<ns;i++){
            if(c<nt){
                m2[s[i]]++;
                if(m1.find(s[i])!=m1.end() && m2[s[i]]<= m1[s[i]])
                    c++;
            }
            while(c==nt && beg <=i){
                if(i-beg+1<mn)
                {
                    mn = i-beg+1;
                    in =beg;
                }
                m2[s[beg]]--;
                
                if(m1.find(s[beg])!=m1.end()&& m2[s[beg]]<m1[s[beg]])
                    c--;
                
                beg++;
            }
            
        }
        if(mn == INT_MAX)
            return "";
        return s.substr(in ,mn);
    }
};
           
