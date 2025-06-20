class Solution {
  public:
    bool validgroup(vector<int> &nums, int k) {
        // code here
        int n = nums.size();
        if(n % k != 0)  return false;
        
        map<int, int> mpp;
        for(int x: nums)    mpp[x]++;

        int i = 0;
        while(!mpp.empty()){
            int st = mpp.begin()->first;
            
            for(int i = 0; i < k; i++){
                int val = st + i;
                if(mpp[val] == 0)   return false;
                
                mpp[val]--;
                if(mpp[val] == 0)   mpp.erase(val);
            }
        }
        return true;
    }
};