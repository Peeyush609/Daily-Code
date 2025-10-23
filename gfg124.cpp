class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        map<float, vector<int>> mpp;
        for(auto it: points){
            int x = it[0];
            int y = it[1];
            float dist = (x)*(x) + (y)*(y);
            mpp[dist] = {x,y};
        }
        
        vector<vector<int>> ans;
        for(auto it: mpp){
            ans.push_back({it.second[0], it.second[1]});
            k--;
            if(k == 0)  break;
        }
        return ans;
    }
};