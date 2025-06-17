class Solution {
public:
    bool compare(char a, char b) {
        if (a > b) {
            swap(a, b);
        }
        return (b - a == 1) || (a == 'a' && b == 'z');
    }

    string resultingString(string s) {
        stack<char> st;
        for(char c : s)
        {
            if  (!st.empty() && compare(c, st.top()))
            {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};