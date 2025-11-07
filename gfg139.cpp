class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
    
        sort(jobs.begin(), jobs.end());
        
        // Min-heap to store {end time, total profit till now}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int maxProfit = 0;
        
        for (auto &job : jobs) {
            int start = job[0], end = job[1], profit = job[2];
            
            // Remove jobs that end before current job starts
            while (!pq.empty() && pq.top().first <= start) {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }
            
            // Push current job with profit + best profit so far
            pq.push({end, profit + maxProfit});
        }
        
        // Final maximum profit among all chains
        while (!pq.empty()) {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }
        
        return maxProfit;
    }

};
