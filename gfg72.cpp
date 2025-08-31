class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        int left = 0;
        int right = n - 1;
        
        while(left < right){
            ans = max(ans, min(arr[left], arr[right])*(right - left));
            
            if(arr[left] < arr[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};