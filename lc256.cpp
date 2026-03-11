class Solution {
public:
    unsigned int bitwiseComplement(int n) {

        if (n == 0) {
            return 1;
        }

        int n_bits = log2(n) + 1;

        unsigned int mask = (1U << n_bits) - 1;

        return n ^ mask;
    }
};