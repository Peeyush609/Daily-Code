class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low + 1;

        if(diff%2 == 0){
            return diff/2;
        }
        else{
            if(low % 2==0){
                return (diff -1)/2;
            }
            else{
                return (diff+1)/2;
            }
        }
        return -1;
    }
};