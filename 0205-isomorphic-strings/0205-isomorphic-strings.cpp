class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int indexS[200] = {0};
        int indexT[200] = {0};

        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (indexS[c1] != indexT[c2])
                return false;

            indexS[c1] = i + 1;
            indexT[c2] = i + 1;
        }
        return true;
    }
};
