class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = 1;
        int ans = 1;

        while (low <= high && high < nums.size()) {

            if (nums[high] == nums[high - 1]) {
                ans = max(ans, high - low + 1);
                high++;
            }

            else if (nums[high] > nums[high - 1] && k > 0) {

                long long val = nums[high] - nums[high - 1];
                long long need = val * (high - low);

                if (need <= k) {
                    k -= need;
                    high++;
                    ans = max(ans, high - low);
                }

                else {
                    k += nums[high - 1] - nums[low];
                    low++;
                }
            }

            else {

                k += nums[high - 1] - nums[low];
                low++;
            }
        }

        return ans;
    }
};