class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = m - 1;
        int size2 = n - 1;
        int i = size1;
        int j = size2;
        int k = n + m - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};