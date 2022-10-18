class Encrypter {
    unordered_map<char,string>key;
    unordered_map<string,int> dict;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++){
            key[keys[i]]  = values[i];
        }
        // dictionary contain decrypted data
        for(auto &it :dictionary){
		// encrypting data 
            string p = encrypt(it);
            dict[p]++;
        }
    }
    
    string encrypt(string word1) {
        string s = "";
        for(int i = 0; i < word1.size();i++){
            s+= (key[word1[i]]);
        }
        return s;
    }
    
    int decrypt(string word2) {
       auto it = dict.find(word2);
       if(it != dict.end())return it->second;
       return 0;
    }

};
