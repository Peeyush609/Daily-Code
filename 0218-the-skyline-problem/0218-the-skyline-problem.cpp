class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int,int>> points;

        for(auto &b : buildings){
            points.push_back({b[0], -b[2]});
            points.push_back({b[1],  b[2]});
        }

        sort(points.begin(), points.end());

        map<int,int> mp;
        mp[0] = 1;

        vector<vector<int>> ans;
        int prev = 0;

        for(auto &p : points){

            int x = p.first;
            int h = p.second;

            if(h < 0){
                mp[-h]++;
            }
            else{
                mp[h]--;
                if(mp[h] == 0)
                    mp.erase(h);
            }

            int cur = mp.rbegin()->first;

            if(cur != prev){
                ans.push_back({x, cur});
                prev = cur;
            }
        }

        return ans;
    }
};