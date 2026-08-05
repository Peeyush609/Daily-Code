class Solution {
public:

    void bfs(int start, vector<int>& visited,
             unordered_map<int, vector<int>>& mpp){

        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty()){

            int curr = q.front();
            q.pop();

            for(auto it: mpp[curr]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        unordered_map<int, vector<int>> mpp;

        for(auto &it: invocations){
            mpp[it[0]].push_back(it[1]);
        }

        vector<int> visited(n, 0);

        // Mark all suspicious methods
        bfs(k, visited, mpp);

        // Check if any non-suspicious method invokes a suspicious one
        for(auto &it: invocations){
            int u = it[0];
            int v = it[1];

            if(visited[u] == 0 && visited[v] == 1){
                vector<int> ans;
                for(int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};