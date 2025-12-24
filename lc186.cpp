class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        int ans = 0;
        int total_apples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());

        for(int  i = 0; i < m; i++){
            if(total_apples <= 0)   break;
            total_apples -= capacity[i];
            ans++;
        }

        return ans;
    }
};