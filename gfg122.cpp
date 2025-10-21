class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> mpp;
        for(int x: arr){
            mpp[x]++;
        }
        
        vector<pair<int, int>> vec;
        for(auto it: mpp){
            vec.push_back({it.first, it.second});
        }
        
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second)
                return a.first > b.first;   // larger first wins in tie
            return a.second > b.second;     // sort by second in descending order
        });
        
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
