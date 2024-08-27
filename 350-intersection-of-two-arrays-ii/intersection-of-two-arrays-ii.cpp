class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> answer;
        if (nums1.size() > nums2.size()) {
            swap(nums2, nums1);
        }
        for (int nums : nums2) {
            count[nums]++;
        }
        for (int nums : nums1) {
            if (count[nums] > 0) {
                answer.push_back(nums);
                count[nums]--;
            }
        }
        return answer;
    }
};