class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // min time to reach a node from src(0)
        vector<int> minTime(V, INT_MAX);
        
        // number of ways to reach a node 
        // from src(0) with minimum cost
        vector<int> paths(V, 0);
        minTime[0] = 0;
        paths[0] = 1;
        
        // sort nodes by time taken to reach 
        // them from src in ascending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int node = top.second;
            int currentTime = top.first;
    
            if (currentTime > minTime[node]) continue;
    
            for (auto& next : adj[node]) {
                int nextNode = next.first;
                int nextTime = next.second;
                int newTime = nextTime + currentTime;
                
                // if newTime is less than stored value
                // then update paths and time
                if (newTime < minTime[nextNode]) {
                    minTime[nextNode] = newTime;
                    paths[nextNode] = paths[node];
                    pq.push({newTime, nextNode});
                } else if (newTime == minTime[nextNode]) {
                    // increment the count of 
                    // paths if time is same
                    paths[nextNode] = (paths[nextNode] + paths[node]);
                }
            }
        }
    
        // return number of paths to reach 
        // dest from src in min time
        return paths[V - 1];
    }
};