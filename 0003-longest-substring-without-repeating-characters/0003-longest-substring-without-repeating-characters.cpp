class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> f;
        int n = s.size();
        int low = 0; int high = 0; int res = INT_MIN;
        while(high<n){
            f[s[high]]++;
            while(f[s[high]]>1){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
            }
            res = max(res,high-low+1); 
            high++;
        }
          return res;
    }
};
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     unordered_map<char,int> freq;
//     int n = s.size();
//     int low = 0, res = 0;
//     for (int high = 0; high < n; high++) {
//         freq[s[high]]++; 
//         while (freq[s[high]] > 1) {
//             freq[s[low]]--;
//             if (freq[s[low]] == 0)
//                 freq.erase(s[low]);
//             low++;
//         }
//         res = max(res, high - low + 1);
//     }
//     return res;
// }

//     };
