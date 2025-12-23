class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        int i;
        int n = s.size();
        for(i=0;i<n;i++){
            freq[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;    
    }
};