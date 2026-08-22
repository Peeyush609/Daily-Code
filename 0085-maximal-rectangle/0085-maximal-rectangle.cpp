class Solution {
public:
    vector<int> psei_func(vector<int>& heights){
        int n = heights.size();
        vector<int> psei(n, -1);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) psei[i] = st.top();
            st.push(i);
        }

        return psei;
    }
    vector<int> nsei_func(vector<int>& heights){
        int n = heights.size();
        vector<int> nsei(n, n);

        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) nsei[i] = st.top();

            st.push(i);
        }

        return nsei;
    }

    int solve(vector<int>& heights){
        int n = heights.size();
        int ans = 0;

        vector<int> psei = psei_func(heights);
        vector<int> nsei = nsei_func(heights);

        // for(int x: psei){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(int x: nsei){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        for(int i = 0; i < n; i++){
            int pr = psei[i];
            int nx = nsei[i];

            int curr = (nx - pr - 1)*heights[i];
            ans = max(ans, curr);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        vector<int> heights(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
                // cout<<heights[j]<<" ";
            }
            // cout<<endl;
            int curr = solve(heights);
            ans = max(ans, curr);
        }

        return ans;
    }
};