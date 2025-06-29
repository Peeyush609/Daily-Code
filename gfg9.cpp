class Solution {
  public:
  
    int count(int mid, vector<int>& nums, int n){
        int c = 1;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum > mid){
                c++;
                sum = nums[i];
            }
        }
        
        return c;
    }
  
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int c = count(mid, arr, n);
            if(c <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};