class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int left = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.size(); right++) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};