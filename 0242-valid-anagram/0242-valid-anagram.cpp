class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1,freq2;
        if(s.length()!=t.length()){
            return false;
        }
       for(auto &p : s){
        freq1[p]++;
       }
       for(auto &p : t){
        freq2[p]++;
       }
       if(freq1==freq2){
        return true;
       }
       return false;
    }
};