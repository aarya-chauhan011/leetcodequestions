class Solution {
public:
    int lengthOfLastWord(string s) {
        const int n = s.size();
        int res = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[n - 1] == ' '){
                if (i != n - 1 && s[i] == ' ' && s[i + 1] != ' ')break;
                if (s[i] == ' ') continue;
                res++;
            }else{
                if (s[i] == ' ') break;
                res++;
            }
        }
        return res;
    }
};