class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& state) {
        // 1 = currently in DFS path -> cycle
        if (state[node] == 1) return false;

        // 2 = already verified safe
        if (state[node] == 2) return true;

        // Mark as currently being explored
        state[node] = 1;

        for (int next : graph[node]) {
            if (!isSafe(next, graph, state)) {
                return false;
            }
        }

        // All outgoing paths lead to safe nodes
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> answer;

        for (int node = 0; node < n; node++) {
            if (isSafe(node, graph, state)) {
                answer.push_back(node);
            }
        }

        return answer;
    }
};