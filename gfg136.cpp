class Solution {
  public:
    
    //TABULATION WAY
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n==1)    return 0;
        // vector<int> dp(n, 0);
        int p = 0;
        int q = abs(height[1] - height[0]);
        
        int ans = q;
        
        //each index of do store the min energy to reach to that index
        for(int i = 2; i<n; i++){
            int one = abs(height[i] - height[i-1]) + q;
            int two = abs(height[i] - height[i-2]) + p;
            
            ans = min(one, two);
            p = q;
            q = ans;
        }
        
        return ans;
    }
    
    
    // //MEMOIZATION way
    // int memo(vector<int>& height, int i, vector<int>& dp){
        
    //     if(i == 0){
    //         return 0;
    //     }
    //     if(dp[i] != -1)   return dp[i];
        
    //     int one = INT_MAX, two = INT_MAX;
        
    //     //if we take 1 steps
    //     one = abs(height[i] - height[i - 1]) + memo(height, i - 1, dp);
    //     //if we take 2 steps
    //     if(i-2 >= 0){
    //         two = abs(height[i] - height[i - 2]) + memo(height, i - 2, dp);
    //     }
        
    //     return dp[i] = min(one, two);
    // }
    
};