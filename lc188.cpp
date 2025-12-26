class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // at x penalty = jitne n x ke strictly left me hai + jitne y x ke right me hai
        vector<int> till_n(n + 1, 0);
        vector<int> forward_y(n + 1, 0);

        for(int i = 1; i <= n; i++){
            if(customers[i - 1] == 'N'){
                till_n[i]++;
            }
            till_n[i] += till_n[i-1];
        }

        for(int i = n - 1; i >= 0; i--){
            if(customers[i] == 'Y'){
                forward_y[i]++;
            }
            forward_y[i] += forward_y[i+1];
        }

        int penalty = INT_MAX;
        int ans = -1;
        for(int i = 0; i <= n; i++){
            int curr_p = till_n[i] + forward_y[i];
            if(curr_p < penalty){
                penalty = curr_p;
                ans = i;
            }
        }

        return ans;
    }
};