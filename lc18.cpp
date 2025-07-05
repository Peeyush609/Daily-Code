class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mpp;
        for(int x: arr){mpp[x] ++;}

        int ans = -1;
        for(auto [x, f]: mpp){
            if(f == x && x > ans)  ans = x;
        }
        return ans;
    }
};