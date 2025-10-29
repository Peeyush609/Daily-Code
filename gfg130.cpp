class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, int dist, int &maxDist, int &farthestNode) {
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }

        for (int nei : adj[node]) {
            if (nei != parent) {
                dfs(nei, node, adj, dist + 1, maxDist, farthestNode);
            }
        }
    }

    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDist = -1, farthestNode = 0;
        dfs(0, -1, adj, 0, maxDist, farthestNode);

        // Second DFS from farthest node
        maxDist = -1;
        dfs(farthestNode, -1, adj, 0, maxDist, farthestNode);

        return maxDist;
    }
};
