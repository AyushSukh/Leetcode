class Solution {
public:
    bool isAlphaNumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }

    char toLowercase(char c) {
        if (c >= 'A' && c <= 'Z')
            return (c - 'A' + 'a');
        return c;
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            while (start < end && !isAlphaNumeric(s[start]))
                start++;
            while (start < end && !isAlphaNumeric(s[end]))
                end--;

            if (toLowercase(s[start++]) != toLowercase(s[end--]))
                return false;
        }
        return true;
    }
};