class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // O(N)
        for(int x: nums){
            int count = 0;
            int sum = 0;
            // O(SQRT(N))
            for(int i = 1; i*i <= x; i++){
                if(x % i == 0){
                    sum += i;
                    count++;
                    if(i*i != x){
                        sum += x/i;
                        count++;
                    }
                }
            }

            if(count == 4)  ans += sum;
        }

        return ans;
    }
};