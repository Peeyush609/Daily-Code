class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
    
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);
    
        // Build reversed adjacency list 
        // and compute indegree for each node
        for (int i = 0; i < V; i++) {
            for (int nextNode : adj[i]) {
                revAdj[nextNode].push_back(i);
                indegree[i]++;
            }
        }
    
        queue<int> q;
        vector<int> ans;
    
        // Push all terminal nodes 
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    
        // Kahn's Algo on reversed graph
        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            ans.push_back(curNode);
    
            for (int prevNode : revAdj[curNode]) {
                indegree[prevNode]--;
                if (indegree[prevNode] == 0) {
                    q.push(prevNode);
                }
            }
        }
    
        // Return safe nodes 
        return ans;
    
    }
};