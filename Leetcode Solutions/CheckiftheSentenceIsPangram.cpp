class Solution {
public:
    bool checkIfPangram(string sentence) {
        
       
        int i=0;
        unordered_set<char>set;
        while(i<sentence.length()){
            
            set.insert(sentence[i]);
            i++;
        }
        if(set.size()==26)return true;
        else{
            return false;
        }
        
        
    }
};
