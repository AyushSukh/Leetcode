class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            map[sortedWord].push_back(word);
        }
        vector<vector<string>> result;
        for (auto it : map) {
            result.push_back(it.second);
        }
        return result;
    }
};