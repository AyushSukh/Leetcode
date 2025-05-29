class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int nonpick = prev;
            int curr = max(pick, nonpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};