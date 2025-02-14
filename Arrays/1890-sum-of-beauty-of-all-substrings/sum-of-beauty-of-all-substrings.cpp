class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int charFrequency[26] = {0};
            int maxFreq = 0, minFreq = INT_MAX;

            for (int j = i; j < n; j++) {
                int charIndex = s[j] - 'a';
                charFrequency[charIndex]++;

                maxFreq = max(maxFreq, charFrequency[charIndex]);

                
                minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (charFrequency[k] > 0) {
                        minFreq = min(minFreq, charFrequency[k]);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
