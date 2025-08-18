class Solution {
  public:
    int calc(vector<int>& nums, int mid){
        // calc the no. of elememnts >= mid
        
        int count = 0;
        for(int x: nums){
            if(x >= mid){
                count++;
            }
        }
        return count;
    }
  
    int hIndex(vector<int>& nums) {
        // code here
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int ans = 0;
        
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int count = calc(nums, mid);
            
            if(count >= mid){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};