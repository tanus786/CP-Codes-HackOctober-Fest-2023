class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> temp(numRows);
        for(int i=0, j=0, fact=1; i<s.length(); i++) {
            temp[j].push_back(s[i]);
            j += fact;
            if(j == numRows-1 || j == 0) fact *= -1;
        }
        s = "";
        for(int i=0; i<numRows; i++) {
            s += temp[i];
        }
        return s;
    }
};
