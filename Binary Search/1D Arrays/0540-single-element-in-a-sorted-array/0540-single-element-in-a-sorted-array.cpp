class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        if (nums.size() == 1 || nums[0] != nums[1])
            return nums[0];
        else if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                ans = nums[mid];
                return ans;
            }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
      return -1;
    }
};