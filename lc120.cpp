class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mpp;
        for(int x: nums){
            int rem = x % value;
            if(rem < 0) rem += value;
            mpp[rem]++;
        }
    
        while(true){
            if(mpp[ans % value] > 0){
                mpp[ans % value]--;
            }
            else{
                return ans;
            }
            ans++;
        }
        return -1;//will never reach here
    }
};