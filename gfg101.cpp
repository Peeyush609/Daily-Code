class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        
        deque<int> minQueue, maxQueue;
        
        int n = arr.size(), start = 0, end = 0;
        
        // Pointers to mark the range of maximum subarray
        int resStart = 0, resEnd = 0;
        while (end < n) {
            
            // Pop the elements greater than current element
            // from min Queue
            while (!minQueue.empty()
                   && arr[minQueue.back()] > arr[end])
                minQueue.pop_back();
                
            // Pop the elements smaller than current element
            // from max Queue
            while (!maxQueue.empty()
                   && arr[maxQueue.back()] < arr[end])
                maxQueue.pop_back();
                
            minQueue.push_back(end);
            maxQueue.push_back(end);
            
            // Check if the subarray has maximum difference less
            // than x
            while (arr[maxQueue.front()] - arr[minQueue.front()]
                   > x) {
                       
                // Reduce the length of sliding window by moving
                // the start pointer
                if (start == minQueue.front())
                    minQueue.pop_front();
                if (start == maxQueue.front())
                    maxQueue.pop_front();
                start += 1;
            }
            
            // Maximize the subarray length
            if (end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
            end += 1;
        }
    
        vector<int> res;
        for (int i = resStart; i <= resEnd; i++)
            res.push_back(arr[i]);
            
        return res;
    }

};