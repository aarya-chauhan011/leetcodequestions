#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];
            if (m1.count(ch)) {
                if (m1[ch] != w) {
                    return false;
                }
            } 
            else if (m2.count(w)) {
                if (m2[w] != ch) {
                    return false;
                }
            } 
            else {
                m1[ch] = w;
                m2[w] = ch;
            }
        }
        return true;
    }
};
