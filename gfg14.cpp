class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int i = 0; 
        int j = 0;
        
        unordered_map<int, int> mpp;
        
        int ans = 0;
        while(j < n){
            
            mpp[arr[j]]++;
            while(mpp.size() > k){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0){
                    mpp.erase(arr[i]);
                }
                i++;
            }
            
            ans += (j - i + 1);
            
            j++;
        }
        
        return ans;
    }
};