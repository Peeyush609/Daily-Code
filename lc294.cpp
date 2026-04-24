class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int l = 0, r = 0;
        for(char c: moves){
            if(c == 'L')    l++;
            else if(c == 'R')          r++;
        }

        return n - 2*min(l, r);
    }
};