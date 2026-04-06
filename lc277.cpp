class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(auto &o : obstacles){
            st.insert({o[0], o[1]});
        }

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;

        int x = 0, y = 0;
        int ans = 0;

        for(int c : commands){
            if(c == -1){
                d = (d + 1) % 4;
            }
            else if(c == -2){
                d = (d + 3) % 4;
            }
            else{
                for(int step = 0; step < c; step++){
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];

                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};
