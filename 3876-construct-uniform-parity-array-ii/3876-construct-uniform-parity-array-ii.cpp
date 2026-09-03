class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        // Base Case: If already all elements are of same parity then true
        bool even = true;
        bool odd = true;
        for(int x: nums1){
            if(x % 2 == 0)  odd = false;
            else            even = false;
        }

        if(even || odd) return true;

        // if min value is odd always possible to create all same parity vector as any greater even no. can minus the smallest no. and the result would be odd so ans would always be true.

        // now lets take the case of the smallest even no.
        // the smallest odd no. would never become even as an odd no. need to be subtracted from that in 
        // order to become even but since it is smallest odd no. so that is not possible here and result would be false.

        int mini = *min_element(nums1.begin(), nums1.end());
        return mini % 2 == 1;
    }
};