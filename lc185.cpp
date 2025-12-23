class Solution {
public:

    //common approach consider all the possibilities and find the max sum
    //but tc: O(n**2)
    // int maxTwoEvents(vector<vector<int>>& events) {
    //     int maxsum=0;
    //     int n=events.size();

    //     for(auto i: events){
    //         for(auto j: events){
    //             //choose the ithe event as the 1st event 
    //             int sum=i[2];
    //             //we want another event which is non overlapping to ith event
    //             //ie j[end]>i[start] or j[start]>i[end]
    //             if(j[1]<i[0] || j[0]>i[1]){
    //                 sum+=j[2];
    //             }
    //             maxsum=max(maxsum, sum);
    //         }
    //     }

    //     return maxsum;
    // }


    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(), events.end());
        int count=0; 

        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(events, 0, count, dp);
    }

    int solve(vector<vector<int>>& events, int i, int count, vector<vector<int>>& dp){
        if(count==2 || i>=events.size()){
            return 0;
        }

        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        //now we have 2 options for every element 
        
        //take that element
        //nextvalidindex repesents the next index we can choose remember the vec is already sorted
        int nextvalidindex=binarysearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextvalidindex, count+1, dp);

        //leave it or not take that element
        //just increment the i nothing else
        int skip= solve(events, i+1, count, dp);

        //now just take the max of both values 
        // Memoize and return the result
        return dp[i][count] = max(take, skip);
    }

    int binarysearch(vector<vector<int>>& events, int endtime){

        //next valid index have the starting value greater than the end of the current index (since array is sorted)
        int low=0;
        int high=events.size()-1;
        int ans=events.size();

        while(low<=high){
            int mid=low+(high-low)/2;

            if(events[mid][0]>endtime){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};