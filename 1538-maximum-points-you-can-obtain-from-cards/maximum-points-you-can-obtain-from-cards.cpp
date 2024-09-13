class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int leftsum = 0;
        int rightsum = 0;
        int sum = 0;
        int rightindex = card.size() - 1;
        for (int i = 0; i < k; i++) {
            leftsum += card[i];
            sum = leftsum;
        }
        for (int i = k - 1; i >= 0; i--) {
            leftsum -= card[i];
            rightsum += card[rightindex];
            rightindex = rightindex - 1;
            sum = max(sum, leftsum + rightsum);
        }
        return sum;
    }
};