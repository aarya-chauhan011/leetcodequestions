class Solution {
public:

    void fun(string &s, int n, int idx, string &diary,
             vector<string> &res,
             unordered_map<char, string> &mp) {

        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = mp[s[idx]];

        for (int j = 0; j < choice.size(); j++) {
            diary.push_back(choice[j]);

            fun(s, n, idx + 1, diary, res, mp);

            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        int n = digits.size();
        string diary = "";
        vector<string> res;

        fun(digits, n, 0, diary, res, mp);

        return res;
    }
};