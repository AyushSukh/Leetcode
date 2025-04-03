class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        pair<int, int> topelement;

        while (k--) {
            topelement = pq.top();
            pq.pop();
        }
        return topelement.first;
    }
};