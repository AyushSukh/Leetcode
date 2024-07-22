class Solution {
public:
    int maxhours(vector<int>& piles) {

        int n = piles.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long totalworkinghours(vector<int>& piles, int j) {
        int n = piles.size();
        long long totalhrs = 0;
        // for (int i = 0; i < n; i++) {
        for (int pile : piles) {
            // totalhrs += ceil((double)piles[i] / (double)j);
            totalhrs += (pile + j - 1) / j;
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxhours(piles);
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhrs = totalworkinghours(piles, mid);
            if (totalhrs <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};