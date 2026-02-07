class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int totalA = 0;
        for (char c : s) {
            if (c == 'a') totalA++;
        }

        int bLeft = 0;
        int aRight = totalA;
        int ans = totalA; // worst case: delete all a's

        for (char c : s) {
            if (c == 'a') {
                aRight--;
            } else {
                bLeft++;
            }

            ans = min(ans, bLeft + aRight);
        }

        return ans;
    }
};
