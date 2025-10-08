class Solution {
public:
    //O(log m)
    int bs(vector<int>& potions, long long success, int x, int m){
        //we want x*potion[i] > success where i is minimum
        //we return n - i ie there are n - i no. in total in portions whose mult. with x > sucsess

        int low = 0;
        int high = m - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long val = (long long)potions[mid] * x;

            if(val < success){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return m - low;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());
        vector<int> ans(n, 0);

        //O(n*logm)
        for(int i = 0; i < n; i++){
            ans[i] = bs(potions, success, spells[i], m);
        }
        return ans;
    }
};