class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int edgeCount = edges.size();

        // Count components using DFS
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // If edges < V-1, cannot connect
        if (edgeCount < V - 1) return -1;

        // Extra edges = total edges - edges used in an acyclic forest
        int extra = edgeCount - (V - components);

        // If enough extra edges to reconnect all components
        if (extra >= (components - 1))
            return components - 1;
        return -1;
    }
};
