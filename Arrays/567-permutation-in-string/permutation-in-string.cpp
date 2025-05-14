class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        vector<int> s1count(26, 0), s2count(26, 0);

        for (int i = 0; i < s1.length(); ++i) {
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1count == s2count)
                return true;
            s2count[s2[i] - 'a']--;
            s2count[s2[i + s1.length()] - 'a']++;
        }

        return s1count == s2count;
    }
};