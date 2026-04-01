class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end()); 

        stack<int> st;

        for(int i = 0; i < n; i++){
            auto &[pos, h, dir, idx] = robots[i];

            if(dir == 'R'){
                st.push(i);
            }
            else{
                while(!st.empty() && h > 0){
                    auto &[p2, h2, d2, idx2] = robots[st.top()];
                    
                    if(d2 != 'R') break;

                    if(h > h2){
                        h--;
                        h2 = 0;
                        st.pop();
                    }
                    else if(h2 > h){
                        h2--;
                        h = 0;
                    }
                    else{
                        h = 0;
                        h2 = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> survivors;

        for(auto &[pos, h, dir, idx] : robots){
            if(h > 0){
                survivors.push_back({idx, h});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> ans;
        for(auto &p : survivors){
            ans.push_back(p.second);
        }

        return ans;
    }
};