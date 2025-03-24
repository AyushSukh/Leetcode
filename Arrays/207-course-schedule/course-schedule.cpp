class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int n = prerequisites.size();
        vector<vector<int>> adjList(numCourses);

        for (int i = 0; i < n; i++) {
            adjList[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }

        vector<int> inDegree(numCourses);

        for (int i = 0; i < numCourses; i++) {
            for (auto it : adjList[i]) {
                inDegree[it]++;
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            res.emplace_back(front);

            for (auto it : adjList[front]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (res.size() == numCourses) {
            return true;
        }

        return false;
    }
};