class Solution {
public:

    // Dijkstra using only straight edges
    vector<int> dijkstra(int src, int n, vector<vector<array<int,3>>> &adj) {
        int INF = 1e9;
        vector<int> dist(n, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            for (auto &x : adj[u]) {
                int v = x[0];
                int straight = x[1];

                if (dist[v] > d + straight) {
                    dist[v] = d + straight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }


    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // Build adjacency list:
        // adj[u] contains {v, straightCost, curvedCost}
        vector<vector<array<int,3>>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int straight = e[2], curved = e[3];

            // undirected graph
            adj[u].push_back({v, straight, curved});
            adj[v].push_back({u, straight, curved});
        }

        // Run Dijkstra from 'a' and 'b'
        vector<int> da = dijkstra(a, V, adj);
        vector<int> db = dijkstra(b, V, adj);

        int INF = 1e9;
        int ans = da[b];   // using no curved edge

        // Try using EACH curved edge once
        for (int u = 0; u < V; u++) {
            for (auto &x : adj[u]) {
                int v = x[0];
                int curved = x[2];

                if (curved < INF) {
                    ans = min(ans, da[u] + curved + db[v]);
                    ans = min(ans, da[v] + curved + db[u]);
                }
            }
        }

        return (ans >= INF ? -1 : ans);
    }
};
