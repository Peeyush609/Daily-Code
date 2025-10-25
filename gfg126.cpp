#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        // Use double for precision (float can cause small errors)
        double sum = accumulate(arr.begin(), arr.end(), 0.0);
        double target = sum / 2.0;

        // Max heap for greedy halving
        priority_queue<double> pq(arr.begin(), arr.end());

        int operations = 0;
        double reduced = 0.0;

        while (reduced < target) {
            double top = pq.top();
            pq.pop();

            double half = top / 2.0;
            reduced += half;      // We reduce total sum by half of top
            pq.push(half);
            operations++;
        }

        return operations;
    }
};
