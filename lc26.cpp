class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;

        while (i < m) {
            // Check if there are still children left to satisfy (j < n)
            if (j < n && players[j] <= trainers[i]) {
                j++;
            }
            i++;
        }

        return j;
    }
};