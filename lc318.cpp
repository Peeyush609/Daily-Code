class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());

        long long m = mass;
        int i = 0;
        while(i < n){
            if(asteroids[i] <= m){
                m += asteroids[i];
            }
            else    return false;

            i++;
        }
        return true;
    }
};