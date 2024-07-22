class Solution {
public:
    void swapifgreater(vector<int>& nums1, vector<int>& nums2, int ind1,
                       int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Resize nums1 to hold all elements
        nums1.resize(m + n);

        // Copy elements from nums2 to the end of nums1
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (right < m) {
                    // Both pointers in the original part of nums1
                    swapifgreater(nums1, nums1, left, right);
                } else if (left < m) {
                    // Left pointer in original nums1, right pointer in the
                    // added part of nums1 (which is nums2)
                    swapifgreater(nums1, nums1, left, right);
                } else {
                    // Both pointers in the added part of nums1 (which is nums2)
                    swapifgreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
