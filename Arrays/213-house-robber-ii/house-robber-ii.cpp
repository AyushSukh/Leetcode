class Solution {
public:
    int robber(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(robber(temp1), robber(temp2));
    }
};