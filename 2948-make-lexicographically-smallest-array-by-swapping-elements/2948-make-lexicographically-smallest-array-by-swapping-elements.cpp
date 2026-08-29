class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); // Sort to process lexicographically

        unordered_map<int, vector<int>> mpp1; // Group index -> elements
        unordered_map<int, int> mpp2;        // Element -> group index

        int a = 0; // Group index
        int i = 0;

        // Group elements based on the limit condition
        while (i < n) {
            mpp1[a].push_back(vec[i]);
            mpp2[vec[i]] = a;

            // Check if the next element can be added to the same group
            if (i < n - 1 && vec[i + 1] - vec[i] > limit) {
                a++; // Start a new group
            }
            i++;
        }

        // Rebuild the nums array with the smallest possible elements
        for (int i = 0; i < n; i++) {
            int a = mpp2[nums[i]];  // Get the group of the current element
            nums[i] = mpp1[a][0];  // Assign the smallest available element
            mpp1[a].erase(mpp1[a].begin()); // Remove the used element
        }

        return nums;
    }
};
