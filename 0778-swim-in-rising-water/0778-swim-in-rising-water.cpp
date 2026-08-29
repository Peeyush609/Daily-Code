class disjointset{
public:
    vector<int> parent, size;
    disjointset(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int ultimateparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = ultimateparent(parent[node]);
    }

    void unionbysize(int u, int v){
        int upu = ultimateparent(u);
        int upv = ultimateparent(v);

        if(upu == upv) return;

        if(size[upu] > size[upv]){
            parent[upv] = upu;
            size[upu] += size[upv];
        }
        else{
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = 0; // Water level

        disjointset ds(n * n); // DSU to manage connectivity between cells

        int target = n * n - 1; // Target is the bottom-right cell
        int start = 0; // Start is the top-left cell
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible moves

        // If the target's ultimate parent is same as ultimate parent of start that means we reached it
        while (ds.ultimateparent(target) != ds.ultimateparent(start)) {
            // Process the cells for the current water level
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Process cell (i, j) only if its water level is <= t
                    if (grid[i][j] <= t) {
                        int node = i * n + j;
                        for (auto& dir : directions) {
                            int x = i + dir.first;
                            int y = j + dir.second;

                            // Make sure the neighbor is within bounds and also submerged
                            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                                int neighbor = x * n + y;
                                ds.unionbysize(node, neighbor); // Union the current cell with its valid neighbor
                            }
                        }
                    }
                }
            }
            // Check if start and target are connected after processing the current water level
            if (ds.ultimateparent(target) == ds.ultimateparent(start)) {
                return t;
            }
            t++; // Increase water level
        }
        
        return t; // Return the current water level when start and target are connected
    }
};
