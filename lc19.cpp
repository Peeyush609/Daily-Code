class FindSumPairs {
public:
    vector<int> n1;
    vector<int> n2;

    unordered_map<int, int> mpp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int x: nums2){
            mpp[x]++;
        }
    }
    
    void add(int index, int val) {
        int old = n2[index];
        int neww = old + val;
        n2[index] = neww;
        mpp[old]--;
        if(mpp[old] == 0){
            mpp.erase(old);
        }
        mpp[neww]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int x: n1){
            int req = tot - x;
            if(mpp.count(req)){
                c += mpp[req];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */