class Solution {
  public:
    // BFS function to find shortest cycle starting from a given node
    int bfs(int start, vector<vector<int>> &adj) {
        int V = adj.size();
    
        // Distance and parent arrays
        vector<int> dist(V, (int)(1e9));
        vector<int> par(V, -1);
    
        queue<int> q;
        dist[start] = 0;
        q.push(start);
    
        int ans = INT_MAX;
    
        while (!q.empty()) {
            int x = q.front();
            q.pop();
    
            for (int child : adj[x]) {
    
                // If not visited yet
                if (dist[child] == (int)(1e9)) {
                    dist[child] = dist[x] + 1;
                    par[child] = x;
                    q.push(child);
                }
    
                // If already visited and not the parent, cycle found
                else if (par[x] != child && par[child] != x) {
                    ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
    
        return ans;
    }
    
    // Function to find length of shortest cycle in the graph
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = INT_MAX;
    
        // Run BFS from every vertex
        for (int i = 0; i < V; i++) {
            ans = min(ans, bfs(i, adj));
        }
    
        // If no cycle found
        if (ans == INT_MAX)
            return -1;
    
        return ans;
    }
};
