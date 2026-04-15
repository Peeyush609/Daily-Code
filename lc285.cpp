class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            int ind = (startIndex + i) % n;

            if(words[ind] == target){
                ans = min(ans, i);
            }
        }

        for(int i = 0; i < n; i++){
            int ind = (startIndex - i + n) % n;

            if(words[ind] == target){
                ans = min(ans, i);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};