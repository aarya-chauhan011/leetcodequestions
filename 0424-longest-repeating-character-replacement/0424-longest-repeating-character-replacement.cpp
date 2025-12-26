class Solution {
public:
    int find(vector<int> &f){
      int  maxc = -1;
        for(int i = 0; i<256;i++){
            maxc = max(maxc,f[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int right = 0; int left = 0; int res = INT_MIN;
        int n = s.size();
        vector<int> f(256, 0);
        while(right<n){
            f[s[right]]++;
            int maxcnt = find(f);
            int len = right - left+1;
            int diff =  len - maxcnt;
            while(diff>k){
                f[s[left]]--;
                left++;
             maxcnt = find(f);
             len = right - left+1;
             diff =  len - maxcnt;
            }
            len=right-left+1;
           res=max(res,len);
        right++;
        }
         return res;
    }
};