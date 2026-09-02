class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAllParts(string s, vector<vector<string>> &ans, vector<string> &parts)
    {
        if (s.size() == 0)
        {
            ans.push_back(parts);  // vector's copy constructor copies automatically
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            string part = s.substr(0, i + 1);
            if (isPalindrome(part))
            {
                parts.push_back(part);
                getAllParts(s.substr(i + 1), ans, parts);
                parts.pop_back();  // undo
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> parts;
        getAllParts(s, ans, parts);
        return ans;
    }
};