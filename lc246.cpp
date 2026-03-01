class Solution {
public:
    int minPartitions(string n) {
        // Hint 1
        // Think about if the input was only one digit. Then you need to add up as many ones as the value of this digit.
        // Hint 2
        // If the input has multiple digits, then you can solve for each digit independently, and merge the answers to form numbers that add up to that input.
        // Hint 3
        // Thus the answer is equal to the max digit
        int ans = -1;
        for(char c:n){
            ans = max(ans, c- '0');
        }
        return ans;
    }
};