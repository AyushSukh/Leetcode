class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string result;

        for (auto& pair : freqVec) {
            result.append(pair.second, pair.first);
        }
        return result;
    }
};