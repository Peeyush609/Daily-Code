class Solution {
public:

    int histogram(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        // Traverse all bars in the histogram
        for (int i = 0; i <= n; i++) {
            // Use sentinel value 0 at the end to ensure we clear the stack at the end
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1; // Calculate the width of the rectangle
                ans = max(ans, h * width); // Update the maximum area
            }
            st.push(i); // Push the index of the current bar onto the stack
        }

        return ans;
    }

    //starting from top treat every row and rows above it as the histogram and calc the max area then include the next row too
    //u will cover all the possible cases
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int ans=0;

        vector<int> vec(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    vec[j]++;
                }else if(matrix[i][j]=='0'){
                    vec[j]=0;
                }
            }

            ans=max(ans, histogram(vec));
        }

        return ans;
    }
};
