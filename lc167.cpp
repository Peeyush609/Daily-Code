class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        int count = 0;
        int tillsum = 0;
        //left subarray sum = tillsum
        //right subarray sum = sum - tllsum
        //difference = sum - 2*tillsum
        for(int i = 0; i < n - 1; i++){
            tillsum += nums[i];
            if((sum - 2*tillsum) % 2 ==0)   count++;
        }

        return count;
    }
};