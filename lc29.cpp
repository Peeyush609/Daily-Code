class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evens = 0;
        int odds = 0;

        for(int x: nums){
            if(x%2 ==0)     evens++;
            else            odds++;        
        }

        int alternate_even_start = 0;
        int alternate_odd_start = 0;

        bool odd = true;
        for(int x : nums){
            if(odd && x%2==0){
                alternate_even_start++;
                odd = false;
            }   
            else if(!odd && x%2 == 1){
                alternate_even_start++;
                odd = true;
            }
        }

        odd = false;
        for(int x : nums){
            if(odd && x%2==0){
                alternate_odd_start++;
                odd = false;
            }   
            else if(!odd && x%2 == 1){
                alternate_odd_start++;
                odd = true;
            }
        }

        return max(max(odds, evens), max(alternate_even_start, alternate_odd_start));
    }
};