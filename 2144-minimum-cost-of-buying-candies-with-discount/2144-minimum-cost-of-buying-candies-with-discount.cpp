class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        
        int total = 0;
        int count = 0;
        
        for(int i = 0; i < cost.size(); i++) {
            if(count == 2) {
                count = 0;  
            } else {
                total += cost[i];  
                count++;
            }
        }
        
        return total;
    }
};