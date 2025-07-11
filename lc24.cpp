class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        vector<long long> lastused(n, 0);
        vector<int> count(n, 0);

        for(auto it: meetings){
            int s = it[0];
            int e = it[1];

            long long mintime = LLONG_MAX;
            int minroom = 0;
            bool found = false;

            for(int room  = 0; room < n; room++){
                if(lastused[room] <= s){
                    lastused[room] = e;
                    count[room]++;
                    found = true;
                    break;
                }

                if(lastused[room] < mintime){
                    mintime = lastused[room];
                    minroom = room;
                }
            }

            if(!found){
                lastused[minroom] += (e - s);
                count[minroom]++;
            }
        }

        int ans = -1;
        int maxi = 0;

        // for(int x: count){
        //     cout<<x<<" ";
        // }

        for(int i = 0; i < n; i++){
            if(count[i] > maxi){
                maxi = count[i];
                ans = i;
            }
        }

        return ans;
    }
};