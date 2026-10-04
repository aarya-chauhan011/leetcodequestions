class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0; int j = n-1 ;
        int high = 0; int res = 1; int low = 1;
        while(low<n){
            if(nums[low]==nums[low-1]){
                low++;
                continue;
            }
                 nums[high+1]=nums[low];
                 high++;
                 res++;
                 low++;
        }
        return res;
    }
};