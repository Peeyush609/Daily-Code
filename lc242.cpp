a.second < b.second;class Solution {
public:

    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second){
            return a < b;
        }
        return a.second < b.second;
    }

    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int, int>> vec;
        for(int x: arr){
            int ones = __builtin_popcount(x);
            vec.push_back({x, ones});
        }

        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans;
        for(auto it: vec){
            ans.push_back(it.first);
        }

        return ans;
    }
};