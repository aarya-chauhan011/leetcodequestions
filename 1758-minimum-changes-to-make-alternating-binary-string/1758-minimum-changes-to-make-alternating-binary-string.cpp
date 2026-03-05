class Solution {
public:
    int minOperations(string s) {
        int changes1 = 0;  // Pattern "010101..."
        
        for(int i = 0; i < s.size(); i++) {
            // Agar expected character match nahi karta
            if(s[i] - '0' != i % 2) {
                changes1++;
            }
        } 
        // Pattern "101010..." ke liye changes = n - changes1
        int changes2 = s.size() - changes1;
        return min(changes1, changes2);
    }
};