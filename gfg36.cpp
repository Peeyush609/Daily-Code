class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        map<int, int> mpp;
        for(int x: arr){
            mpp[x]++;
        }
        
        vector<int> ans;
        for(auto it: mpp){
            int x = it.first;
            int f = it.second;
            if(f > n/3){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};