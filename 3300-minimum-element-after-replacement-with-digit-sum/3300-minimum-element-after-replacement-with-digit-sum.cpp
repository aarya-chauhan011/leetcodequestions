class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];
            int sum = 0 ;
        
        while(num!=0){
            sum = sum+num%10;
            num = num/10;
        }
        minSum = min(minSum,sum);
    }
    return minSum;
    }
};