class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {
            int odd = expandoncenter(s, i, i);
            int even = expandoncenter(s, i, i + 1);
            int maxlen = max(odd, even);

            if (maxlen > end - start) {
                start = i - (maxlen - 1) / 2;
                end = i + maxlen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandoncenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};