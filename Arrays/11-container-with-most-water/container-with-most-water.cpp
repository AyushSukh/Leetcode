class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while (left < right) {
            // Compute the area
            int h = min(height[left], height[right]);
            result = max(result, (right - left) * h);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                // Skip all lines shorter than the current left (they can't give
                // a larger area)
                do {
                    left++;
                } while (left < right && height[left] < h);
            } else {
                // Skip all lines shorter than the current right (they can't
                // give a larger area)
                do {
                    right--;
                } while (left < right && height[right] < h);
            }
        }
        return result;
    }
};