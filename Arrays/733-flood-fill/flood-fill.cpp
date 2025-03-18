class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int newColor, int inicolor) {
        ans[row][col] = newColor;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = image.size();
        int m = image[0].size();

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    if (abs(delrow) == abs(delcol))
                        continue;

                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        image[nrow][ncol] == inicolor &&
                        ans[nrow][ncol] != newColor) {
                        ans[nrow][ncol] = newColor;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int inicolor = image[sr][sc];
        if (inicolor == newColor)
            return image;
        vector<vector<int>> ans = image;

        bfs(sr, sc, ans, image, newColor, inicolor);
        return ans;
    }
};
