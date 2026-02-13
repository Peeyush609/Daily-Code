class Solution {
public:
    // Global array to prevent stack overflow and reuse memory
    int prefix_counts[100001][3]; 
    int n, max_len = 1, current_run = 1;

    int longestBalanced(string s) {
        n = s.size();
        
        // Step 1: Preprocessing Prefix Sums & Initial Ans
        for(int i = 0; i < n; ++i) {
            // Copy previous state
            for(int j = 0; j < 3; ++j) {
                prefix_counts[i+1][j] = prefix_counts[i][j];
            }
            // Update current char count
            ++prefix_counts[i+1][s[i]-'a'];

            // Optimization: The longest contiguous segment of a single char
            // is a valid balanced string. Use it as a lower bound for max_len.
            if(i && s[i] == s[i-1]) {
                ++current_run;
                max_len = max(max_len, current_run);
            } else {
                current_run = 1;
            }
        }

        // Step 2: Main Logic with Pruning
        // Only iterate if a longer answer is theoretically possible
        for(int start = 0; start + max_len <= n; ++start) {
            
            // Start checking from the current best length
            for(int end = start + max_len; end <= n; ) {
                
                int max_freq = 0, unique_chars = 0, count;
                
                // Calculate stats for s[start...end-1]
                for(int k = 0; k < 3; ++k) {
                    count = prefix_counts[end][k] - prefix_counts[start][k];
                    max_freq = max(max_freq, count);
                    if(count) ++unique_chars;
                }

                int current_len = end - start;
                int target_len = max_freq * unique_chars;

                // Check for balance
                if(target_len == current_len) {
                    max_len = max(max_len, current_len);
                    // Try next immediate length
                    ++end; 
                } else {
                    // PRUNING: Jump directly to the theoretical minimum length
                    // Any length between current_len and target_len cannot be balanced
                    end = start + target_len;
                }
            }
        }
        return max_len;
    }
};