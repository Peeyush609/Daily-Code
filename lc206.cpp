class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        set<int, greater<int>> s1, s2;

        for(int i = 0; i < hFences.size(); i++){
            for(int j = i + 1; j < hFences.size(); j++){
                s1.insert(hFences[j] - hFences[i]);
            }
        }

        for(int i = 0; i < vFences.size(); i++){
            for(int j = i + 1; j < vFences.size(); j++){
                s2.insert(vFences[j] - vFences[i]);
            }
        }

        int mod = 1e9 + 7;
        for(long long x: s1){
            if(s2.count(x)){
                return x*x % mod;
            }
        }

        return -1;
    }
};