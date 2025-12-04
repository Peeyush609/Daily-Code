class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

// Any leading cars that are all 'L' (from the start) will go off to the left forever and never collide with anyone.​

// Any trailing cars that are all 'R' (from the end) will go off to the right forever and never collide with anyone.​

// After removing those, in the remaining middle segment, every 'L' or 'R' car is guaranteed to eventually collide with something and stop.

        int l = 0;
        int r = n - 1;
        while(l < n && directions[l] == 'L'){
            l++;
        }
        while(r >= 0 && directions[r] == 'R'){
            r--;
        }

        int ans = 0;
        for(int i = l; i <= r; i++){
            if(directions[i] != 'S'){
                ans++;
            }
        }
        return ans;
    }
};