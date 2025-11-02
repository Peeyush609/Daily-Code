class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        // Count existing edges from adjacency list
        int existingEdges = 0;
        for (int u = 0; u < V; u++) {
            existingEdges += adj[u].size();
        }
    
        int maxEdges = V * (V - 1) / 2;
    
        // Subtract existing edges to get how many more we can add
        return maxEdges - existingEdges;
    }
};
