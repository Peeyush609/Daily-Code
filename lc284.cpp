class Solution {
public:

    long long solve(int i, int j, vector<int>& robot, vector<int>& fact, int n, int m, vector<vector<long long>>& dp){
        if(i == n){
            return 0;
        }
        if(j == m){
            return 1e15;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        long long take = abs(robot[i] - fact[j]) + solve(i + 1, j + 1, robot, fact, n, m, dp);
        long long skip = solve(i, j + 1, robot, fact, n, m, dp);

        return dp[i][j] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fact;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < factory[i][1]; j++){
                fact.push_back(factory[i][0]);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(fact.size(), -1));
        long long ans = solve(0, 0, robot, fact, n, fact.size(), dp);
        return ans;
    }
};