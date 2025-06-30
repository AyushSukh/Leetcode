class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> new_row;
            new_row.push_back(1);
            for (int j = 1; j < i; j++) {
                new_row.push_back(row[j - 1] + row[j]);
            }
            new_row.push_back(1);
            row = new_row;
        }
        return row;
    }
};