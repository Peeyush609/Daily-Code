class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> diff;
        //push the 1st diff 
        //0 from the 1st starting point
        diff.push_back(startTime[0] - 0);

        //push all the middle differences
        for(int i = 0 ; i < n - 1; i++){
            int e = endTime[i];
            int s = startTime[i + 1];
            diff.push_back(s - e);
        }

        //push the last diff
        //from end of lasttime and endpoint
        diff.push_back(eventTime - endTime[n - 1]);

        for(int x: diff){
            cout<<x<<" ";
        }

        //now we need the max k+1 adj diff
        int i = 0; 
        int j = 0;

        int sum = 0;
        while(j < k + 1){
            sum += diff[j];
            j++;
        }

        int maxi = sum;
        int len = diff.size();
        while(j < len){
            sum += (diff[j] - diff[i]);
            maxi = max(maxi, sum);
            i++;
            j++;
        }

        return maxi;
    }
};