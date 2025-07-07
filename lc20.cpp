class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        int ans = 0;
        int day = 0;
        priority_queue<int, vector<int>, greater<int>> pq;//minheap

        int i = 0;
        while(!pq.empty() || i < n){
            if(pq.empty()){
                int day = events[i][0];
            }

            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            day++;
        }

        return ans;
    }
};