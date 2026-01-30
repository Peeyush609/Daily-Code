class Trie {
public:
    Trie* child[26];
    int id;

    Trie() {
        fill(child, child + 26, nullptr);
        id = -1;
    }
};

class Solution {
    static constexpr int INF = INT_MAX / 2;

    // Insert word into Trie and assign an ID if new
    int insertWord(Trie* root, const string& word, int& idCounter) {
        Trie* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        if (node->id == -1) {
            node->id = ++idCounter;
        }
        return node->id;
    }

    // Relax DP value
    void relax(long long& cur, long long val) {
        if (cur == -1 || val < cur) {
            cur = val;
        }
    }

public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        Trie* root = new Trie();
        int idCounter = -1;

        // Graph for string transformations
        vector<vector<int>> dist(2 * m, vector<int>(2 * m, INF));
        for (int i = 0; i < 2 * m; i++) dist[i][i] = 0;

        // Build Trie + Graph
        for (int i = 0; i < m; i++) {
            int u = insertWord(root, original[i], idCounter);
            int v = insertWord(root, changed[i], idCounter);
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd-Warshall: all-pairs shortest paths
        for (int k = 0; k <= idCounter; k++) {
            for (int i = 0; i <= idCounter; i++) {
                for (int j = 0; j <= idCounter; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // DP: dp[i] = min cost for prefix [0..i]
        vector<long long> dp(n, -1);

        for (int start = 0; start < n; start++) {
            if (start > 0 && dp[start - 1] == -1) continue;

            long long baseCost = (start == 0 ? 0 : dp[start - 1]);

            // Case 1: characters are equal
            if (source[start] == target[start]) {
                relax(dp[start], baseCost);
            }

            // Case 2: substring replacement
            Trie* sNode = root;
            Trie* tNode = root;

            for (int end = start; end < n; end++) {
                sNode = sNode ? sNode->child[source[end] - 'a'] : nullptr;
                tNode = tNode ? tNode->child[target[end] - 'a'] : nullptr;
class Trie {
public:
    Trie* child[26];
    int id;

    Trie() {
        fill(child, child + 26, nullptr);
        id = -1;
    }
};

class Solution {
    static constexpr int INF = INT_MAX / 2;

    // Insert word into Trie and assign an ID if new
    int insertWord(Trie* root, const string& word, int& idCounter) {
        Trie* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        if (node->id == -1) {
            node->id = ++idCounter;
        }
        return node->id;
    }

    // Relax DP value
    void relax(long long& cur, long long val) {
        if (cur == -1 || val < cur) {
            cur = val;
        }
    }

public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        Trie* root = new Trie();
        int idCounter = -1;

        // Graph for string transformations
        vector<vector<int>> dist(2 * m, vector<int>(2 * m, INF));
        for (int i = 0; i < 2 * m; i++) dist[i][i] = 0;

        // Build Trie + Graph
        for (int i = 0; i < m; i++) {
            int u = insertWord(root, original[i], idCounter);
            int v = insertWord(root, changed[i], idCounter);
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd-Warshall: all-pairs shortest paths
        for (int k = 0; k <= idCounter; k++) {
            for (int i = 0; i <= idCounter; i++) {
                for (int j = 0; j <= idCounter; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // DP: dp[i] = min cost for prefix [0..i]
        vector<long long> dp(n, -1);

        for (int start = 0; start < n; start++) {
            if (start > 0 && dp[start - 1] == -1) continue;

            long long baseCost = (start == 0 ? 0 : dp[start - 1]);

            // Case 1: characters are equal
            if (source[start] == target[start]) {
                relax(dp[start], baseCost);
            }

            // Case 2: substring replacement
            Trie* sNode = root;
            Trie* tNode = root;

            for (int end = start; end < n; end++) {
                sNode = sNode ? sNode->child[source[end] - 'a'] : nullptr;
                tNode = tNode ? tNode->child[target[end] - 'a'] : nullptr;

                if (!sNode || !tNode) break;

                if (sNode->id != -1 && tNode->id != -1 &&
                    dist[sNode->id][tNode->id] < INF) {
                    relax(dp[end], baseCost + dist[sNode->id][tNode->id]);
                }
            }
        }

        return dp[n - 1];
    }
};

                if (!sNode || !tNode) break;

                if (sNode->id != -1 && tNode->id != -1 &&
                    dist[sNode->id][tNode->id] < INF) {
                    relax(dp[end], baseCost + dist[sNode->id][tNode->id]);
                }
            }
        }

        return dp[n - 1];
    }
};
