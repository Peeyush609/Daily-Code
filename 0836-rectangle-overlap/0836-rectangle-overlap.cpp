class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if width and height of intersection are both positive
        int x_overlap = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int y_overlap = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        
        return x_overlap > 0 && y_overlap > 0;
    }
};