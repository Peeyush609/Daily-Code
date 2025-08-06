class Solution {
    vector<int> segTree;
    
    void constructTree(const vector<int>& baskets, int st, int end, int n) {
        if (st == end) {
            segTree[n] = baskets[st];
            return;
        }
        int mid = (st + end) / 2;
        constructTree(baskets, st, mid, 2 * n);
        constructTree(baskets, mid + 1, end, 2 * n + 1);
        segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
    }
    
    int search(int n, int st, int end, int k) {
        if (segTree[n] < k) return -1;
        if (st == end) {
            segTree[n] = -1;
            return st;
        }
        int mid = (st + end) / 2;
        int pos = (segTree[2 * n] >= k) ? search(2 * n, st, mid, k) : search(2 * n + 1, mid + 1, end, k);
        segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
        return pos;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.assign(4 * n, 0);
        constructTree(baskets, 0, n - 1, 1);
        int unplaced = 0;
        
        for (int fruit : fruits) {
            if (search(1, 0, n - 1, fruit) == -1) 
                unplaced++;
        }
        
        return unplaced;
    }
};