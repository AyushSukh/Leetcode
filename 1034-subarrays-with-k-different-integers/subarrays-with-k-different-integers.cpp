class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0;
        map<int, int> map;
        while (r < nums.size()) {
            map[nums[r]]++;
            while (map.size() > k) {
                map[nums[l]]--;

                if (map[nums[l]] == 0)
                    map.erase(nums[l]);

                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};