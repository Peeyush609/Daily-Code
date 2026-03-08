class Solution {
public:
    string help(unordered_set<string>& ss, int n, string s){
        if(s.size() == n){
            if(ss.count(s))     return "";
            else                return s;
        }

        string z = help(ss, n, s + '0');
        string o = help(ss, n, s + '1');

        if(z != "") return z;
        else if(o != "")    return o;

        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> ss(nums.begin(), nums.end());
        return help(ss, n, "");
    }
};