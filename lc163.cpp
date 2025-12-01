class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPower = 0;
        for (int power : batteries)
            sumPower += power;  // total available power [web:2]

        long long left = 1, right = sumPower / n;

        while (left < right) {
            long long target = right - (right - left) / 2;  // mid biased to the right
            long long extra = 0;

            for (int power : batteries)
                extra += min<long long>(power, target);  // how much each battery can contribute to 'target'

            if (extra >= (long long)n * target)
                left = target;
            else
                right = target - 1;
        }
        return left;
    }
};
