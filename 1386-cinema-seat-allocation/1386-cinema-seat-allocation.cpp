class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (auto &seat : reservedSeats) {
            mp[seat[0]].push_back(seat[1]);
        }
        long long ans = 2LL * n;
        for (auto &it : mp) {
            int row = it.first;
            vector<int> seats = it.second;

            bool left = true;   
            bool middle = true;  
            bool right = true;   

            for (int s : seats) {
                if (s >= 2 && s <= 5)
                    left = false;

                if (s >= 4 && s <= 7)
                    middle = false;

                if (s >= 6 && s <= 9)
                    right = false;
            }
            ans -= 2;

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};