class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        function<void(int, int, string)> depthFirstSearch =
            [&](int leftCount, int rightCount, string current) {
                if (leftCount > n || rightCount > n || leftCount < rightCount)
                    return;
                if (leftCount == n && rightCount == n) {
                    result.push_back(current);
                    return;
                }
                depthFirstSearch(leftCount + 1, rightCount, current + '(');
                depthFirstSearch(leftCount, rightCount + 1, current + ')');
            };
        depthFirstSearch(0, 0, "");
        return result;
    }
};