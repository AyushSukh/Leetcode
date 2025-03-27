class Solution {
public:
#define ll long long
    static const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<ll> time(n, LLONG_MAX);
        time[0] = 0;

        vector<ll> way(n, 0);
        way[0] = 1;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            ll currtime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int timetotravel = it.second;
                if (currtime + timetotravel < time[adjnode]) {
                    time[adjnode] = currtime + timetotravel;
                    pq.push({time[adjnode], adjnode});
                    way[adjnode] = way[node] % mod;
                } else if (currtime + timetotravel == time[adjnode])
                    way[adjnode] = (way[adjnode] + way[node]) % mod;
            }
        }
        return way[n - 1];
    }
};