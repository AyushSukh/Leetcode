class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0;
        int maxsum = INT_MIN;

        for (int num : nums) {
            currentsum += num;
            maxsum = max(maxsum, currentsum);

            if (currentsum < 0) {
                currentsum = 0;
            }
        }
        return maxsum;
    }
};