class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {1};  // Safety check for empty input
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 10 - 1) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};