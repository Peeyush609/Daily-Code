class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Build the adjacency list
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int result = 0;

        // Helper function for DFS
        function<long long(int, int)> dfs = [&](int node,
                                                int parent) -> long long {
            // Sum of the current subtree
            long long subtree_sum = values[node];

            // Traverse neighbors
            for (int neighbor : tree[node]) {
                if (neighbor != parent) {
                    subtree_sum += dfs(neighbor, node);
                }
            }

            // Check if the subtree sum is divisible by k
            if (subtree_sum % k == 0) {
                result++;
                return 0; // Reset the sum after forming a valid component
            }
            return subtree_sum;
        };

        // Start DFS from node 0 (arbitrary root)
        dfs(0, -1);
        return result;
    }
};