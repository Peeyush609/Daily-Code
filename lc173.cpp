class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        unordered_map<int, set<int>> row, col;

        for(auto &b: buildings){
            int x = b[0], y = b[1];

            row[x].insert(y);
            col[y].insert(x);
        }

        for(auto &b : buildings){
            int x = b[0], y = b[1];

            auto left = row[x].lower_bound(y);
            bool lefti = (left != row[x].begin());
            
            auto right = row[x].upper_bound(y);
            bool righti = (right != row[x].end());
            
            auto up = col[y].lower_bound(x);
            bool upi = (up != col[y].begin());
            
            auto down = col[y].upper_bound(x);
            bool downi = (down != col[y].end());

            if(upi && lefti && downi && righti){
                ans++;
            }
        }

        return ans;
    }
};