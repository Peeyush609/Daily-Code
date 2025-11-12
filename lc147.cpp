class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        //final steps = steps to make first 1  + rem numbers
        int ones =  0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)    ones++;
        }

        if(ones > 0)    return n - ones;

        // If no 1 is present, we must create the first 1.

        // Since the operation is only allowed on adjacent elements, you must find the shortest subarray with gcd = 1 using only adjacent steps.

        // Suppose the shortest such subarray is from index i to j (j - i + 1 elements), and GCD of this subarray is 1.

        // Then we can make the element at index i into 1 in j - i operations.

        // Once we have a 1, it takes n - 1 more operations to make all elements 1.

        // ✅ Total operations = (length of subarray - 1) + (n - 1) = n + (length - 2)

        int minsub = n + 1;
        for(int i = 0; i < n; i++){
            int gc = nums[i];
            for(int j = i + 1; j < n; j++){
                gc = gcd(gc, nums[j]);
                if(gc == 1){
                    minsub = min(minsub, j - i + 1);
                }
            }
        }

        if(minsub > n)  return -1;//ie all have a common divisor that is not one obviously as we have taken that case before

        return (minsub - 1) + (n - 1);
    }
};