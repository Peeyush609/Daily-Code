class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            int s = startTime[i];
            int e = endTime[i];
            if(s <= queryTime && e >= queryTime){
                ans++;
            }
        }

        return ans;
    }
};