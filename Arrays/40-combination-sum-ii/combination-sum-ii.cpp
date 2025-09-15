class Solution {
public:
    void helper(vector<int>& candidates, int target, int ind,
                vector<vector<int>>& ans, vector<int>& ds) {
        int n = candidates.size();

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (i != ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(candidates, target, 0, ans, ds);
        return ans;
    }
};