class Solution {
public:

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> free;
        //push the 1st free slot 
        //0 from the 1st starting point
        free.push_back(startTime[0]);

        //push all the middle free slots
        for(int i = 0 ; i < n - 1; i++){
            int e = endTime[i];
            int s = startTime[i + 1];
            free.push_back(s - e);
        }

        //push the last free slot
        //from end of lasttime and endpoint
        free.push_back(eventTime - endTime[n - 1]);

        //now free has n + 1 elements
        int maxi = 0;

        for(int i = 0; i < n; i++){
            //abhi bhi adjacent wala option to hai hi
            maxi = max(maxi, free[i] + free[i + 1]);
        }

        //remember free pre and suff all contains n + 1 elements
        //1 starting free time 1 ending and n - 1 midle free solts

        vector<int> pre = free;
        vector<int> suf = free;

        for(int i = 1; i <= n; i++){
            pre[i] = max(pre[i], pre[i - 1]);
        }

        for(int i = n - 1; i >= 0; i--){
            suf[i] = max(suf[i], suf[i + 1]);
        }
        
        auto check = [&](int i, int duration){
            //if this meet can be shifted somewhere before
            if(i > 0 && pre[i -1] >= duration)  return true;

            //if this meet can be shifted somewhere before
            // i+2 as we cant use the next adjacent space too
            if(i + 2 < n + 1 && suf[i + 2] >= duration)  return true;

            //this meet cant be chofted anywhere else 
            return false;
        };

        for(int i = 0; i < n; i++){
            int duration = endTime[i] - startTime[i];
            if(check(i, duration)){
                maxi = max(maxi, free[i] + duration + free[i + 1]);
            }
        }

        return maxi;
        
    }
};