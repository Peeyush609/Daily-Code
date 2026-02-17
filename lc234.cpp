class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {              // valid hours: 0–11 [web:6]
            for (int m = 0; m < 60; ++m) {          // valid minutes: 0–59 [web:6]
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // hour without leading zero, minute with two digits [web:6][web:8]
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};

