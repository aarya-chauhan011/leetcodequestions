// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int left = 0, right = s.size() - 1;
//         while (left < right) {
//             swap(s[left],s[right]);
//             left++;
//             right--;
//         }
//     }
// };
    class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> reverse;
        for(char c : s) {
            reverse.push(c);
        }
        s.clear();  // Empty the vector
        while(!reverse.empty()) {
            s.push_back(reverse.top());
            reverse.pop();
        }
    }
};
 