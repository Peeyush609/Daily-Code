class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(!((x2 >= x1 && y1 >= y2) || (x1 >= x2 && y2 >= y1))) continue;

                bool poss = true;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)    continue;
                    int x = points[k][0];
                    int y = points[k][1];
                    if(min(x1,x2) <= x && x <= max(x1, x2) && min(y1,y2) <= y && y <= max(y1, y2)){
                        poss = false;
                        break;
                    }
                }

                if(poss){
                    ans++;
                    // cout<<x1<<" "<<y1<<endl;
                    // cout<<x2<<" "<<y2<<endl;
                }    
            }
        }
        return ans;
    }
};