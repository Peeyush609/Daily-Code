class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(m != n)  return false;

        string t = s;
        t += s;
        for(int i = 0; i < n; i++){
            if(t.substr(i, n) == goal)  return true;
        }
        return false;
    }
};