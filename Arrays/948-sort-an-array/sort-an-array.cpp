class Solution {
public:
    void quicksort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = randomized_partition(nums, low, high);
            quicksort(nums, low, pi - 1);
            quicksort(nums, pi + 1, high);
        }
    }

    int randomized_partition(vector<int>& nums, int low, int high) {
        int randomIndex =
            low + rand() % (high - low + 1); // \U0001f525 Random pivot selection
        swap(nums[randomIndex],
             nums[high]); // Swap random pivot with last element
        return partition(nums, low, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0)); // \U0001f525 Seed for randomness
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
