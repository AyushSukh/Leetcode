class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        if (n == 0)
            return 0;

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    count += 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};