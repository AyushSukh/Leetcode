class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto num : nums) {
            int i = abs(num) - 1;
            nums[i] = -1 * (abs(nums[i]));
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};