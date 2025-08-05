class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> used(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            bool fill = false;
            for(int j = 0; j < n; j++){
                if(used[j] == 0 && baskets[j] >= fruits[i]){
                    used[j] = 1;
                    fill = true;
                    break;
                }
            }
            if(!fill) ans ++;
        }

        return ans;
    }
};