class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;              // already at end
        if(arr[0] == 0) return -1;        // stuck at start
        
        int maxReach = arr[0];   // farthest we can reach
        int steps = arr[0];      // steps left in current jump
        int jumps = 1;           // we must take at least one jump
        
        for(int i = 1; i < n; i++) {
            // reached end
            if(i == n - 1) return jumps;
            
            maxReach = max(maxReach, i + arr[i]);
            steps--;
            
            // no more steps left → must take another jump
            if(steps == 0) {
                jumps++;
                
                // If current index is beyond maxReach → cannot proceed
                if(i >= maxReach) return -1;
                
                // reset steps for the new jump
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
