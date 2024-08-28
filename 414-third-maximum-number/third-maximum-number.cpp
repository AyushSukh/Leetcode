class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> count(nums.begin(), nums.end());
        if (count.size() < 3) {
            return *count.rbegin();
        }
        auto it = count.rbegin(); // Points to the largest element
        ++it;                     // Points to the second largest element
        ++it;
        return *it;
    }
};