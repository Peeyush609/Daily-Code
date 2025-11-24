class DSU {
public:
    vector<int> parent, rankv;
    
    DSU(int n) : parent(n), rankv(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int runKruskal(int n, vector<vector<int>> &edges, int skipU, int skipV) {
    DSU dsu(n);
    int cost = 0, taken = 0;

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        
        // Skip this particular MST edge
        if ((u == skipU && v == skipV) || (u == skipV && v == skipU))
            continue;

        if (dsu.unite(u, v)) {
            cost += w;
            taken++;
        }
    }

    if (taken != n - 1) return INT_MAX; // invalid MST
    return cost;
}

class Solution {
  public:
    int secondMST(int V, vector<vector<int>> &edges) {
        
        // Sort edges by weight
        sort(edges.begin(), edges.end(),
            [](auto &a, auto &b){ return a[2] < b[2]; });
        
        // Build MST
        DSU dsu(V);
        int mstCost = 0;
        vector<pair<int,int>> mstEdges;  // only store (u,v)

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dsu.unite(u, v)) {
                mstCost += w;
                mstEdges.push_back({u, v});
            }
        }

        // Try removing each MST edge
        int secondBest = INT_MAX;

        for (auto &e : mstEdges) {
            int cost = runKruskal(V, edges, e.first, e.second);
            if (cost > mstCost && cost < secondBest)
                secondBest = cost;
        }

        return secondBest == INT_MAX ? -1 : secondBest;
    }
};
