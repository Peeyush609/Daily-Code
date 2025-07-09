/*

Sum of subarray minimum

Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

Examples:

Input: arr[] = [3, 1, 2, 4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.


Input: arr[] = [71, 55, 82, 55]
Output: 593
Explanation: The sum of the minimum of all the subarrays is 593.


Constraints:
1 ≤ arr.size() ≤ 3*104
1 ≤ arr[i] ≤ 103

*/

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> pse(n, 0);//previous smalleer element (<)
        vector<int> nse(n, 0);//next smaller element(<=)
        
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            nse[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        
        while (!st.empty()) {
            st.pop();
        }
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            pse[i] = st.empty() ? -1 : st.top();
            
            st.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans += arr[i]*(nse[i] - i)*(i - pse[i]);
        }
        
        
        
        return ans;
    }
};

