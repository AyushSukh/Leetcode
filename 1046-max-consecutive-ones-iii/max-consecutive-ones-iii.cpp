class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int len = 0;
        int maxlen = 0;
        int zeroes = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                zeroes++;
            if (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            if (zeroes <= k) {
                len = right - left + 1;
            }
            maxlen = max(maxlen, len);
            right++;
        }
        return maxlen;
    }
};