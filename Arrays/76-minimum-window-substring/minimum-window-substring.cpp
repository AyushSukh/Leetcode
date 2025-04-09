class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIndex = 0;
        int count = t.length();

        while (right < s.length()) {
            char ch = s[right];

            if (map[ch] > 0) {
                count--;
            }
            map[ch]--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                map[s[left]]++;
                if (map[s[left]] > 0) {
                    count++;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};