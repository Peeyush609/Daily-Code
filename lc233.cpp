class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) | (n & 1);  // append lowest bit of n
            n >>= 1;                     // move to next bit
        }
        return res;
    }
};
