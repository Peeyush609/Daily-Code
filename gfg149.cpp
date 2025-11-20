class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        int n = s.size();
        const int INF = 1e9;

        // Step 1: Create cost matrix for 26x26 characters
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // cost to convert same char -> 0
        for(int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // fill direct edges
        for(int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Step 2: Floyd-Warshall to compute all-pairs shortest transformation cost
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 3: For each index, compute minimum cost to make s[i] and t[i] same
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if(a == b) continue;

            int best = INF;

            // Try making both equal to character c (0 to 25)
            for(int c = 0; c < 26; c++) {
                if(dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }

            if(best == INF) return -1;
            ans += best;
        }

        return ans;
    }
};
