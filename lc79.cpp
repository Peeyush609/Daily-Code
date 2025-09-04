class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist_x = abs(z - x);
        int dist_y = abs(z - y);

        if(dist_x < dist_y) return 1;
        else if(dist_x > dist_y) return 2;
        return 0;        
    }
};