class DSU {
    vector<int> parent, rank;
    int components;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        components = n;
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp) return;

        if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else {
            parent[xp] = yp;
            rank[yp]++;
        }
        components--;
    }

    bool isSingle() {
        return components == 1;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU d(n);
        int ans = 0, count = 0;

        for (auto edge : edges) {
            int w = edge[0], u = edge[1], v = edge[2];
            if (d.find(u) != d.find(v)) {
                d.Union(u, v);
                ans += w;
                count++;
                if (count == n - 1) break;
            }
        }

        return ans;
    }
};
