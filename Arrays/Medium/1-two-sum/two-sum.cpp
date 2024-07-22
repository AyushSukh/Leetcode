class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of indices
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, 2, ..., n-1
        
        // Sort the indices based on the corresponding values in nums
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[indices[left]] + nums[indices[right]];
            if (sum == target) {
                // Return the indices
                return {indices[left], indices[right]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
        
    }
};