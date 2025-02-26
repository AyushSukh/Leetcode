class Solution {
public:
    void dfs(int node, vector<int> adjls[], vector<int>& visit) {
        visit[node] = 1;
        for (auto it : adjls[node]) {
            if (!visit[it]) {
                dfs(it, adjls, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjls[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> visit;
        for (int i = 0; i < n; i++) {
            visit.push_back(0);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                cnt++;
                dfs(i, adjls, visit);
            }
        }
        return cnt;
    }
};