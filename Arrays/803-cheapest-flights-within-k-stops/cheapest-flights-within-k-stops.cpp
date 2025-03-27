class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto i : flights) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> tempDist = dist;  // Create a temporary distance array

            while (size--) {
                int stops = q.front().first;
                int node = q.front().second.first;
                int weight = q.front().second.second;
                q.pop();

                if (stops > k) continue;

                for (auto i : adj[node]) {
                    int adjNode = i.first;
                    int edgeWeight = i.second;

                    if (weight + edgeWeight < tempDist[adjNode]) {  
                        tempDist[adjNode] = weight + edgeWeight;
                        q.push({stops + 1, {adjNode, tempDist[adjNode]}});
                    }
                }
            }

            dist = tempDist;  
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
