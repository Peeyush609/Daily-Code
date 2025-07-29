class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        
        for(int i = 0; i < n; i++){
            int ind = s[i] - 'a';
            if(first[ind] == -1){
                first[ind] = i;
            }
            last[ind] = i;
        }
        
        vector<int> pre_ascii_sum(n, 0);
        pre_ascii_sum[0] = (int)s[0];
        for(int i = 1; i < n; i++){
            pre_ascii_sum[i] = pre_ascii_sum[i-1] + (int)s[i];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int ind = s[i] - 'a';
            if(i == first[ind] && first[ind] != last[ind]){
                int sum = pre_ascii_sum[last[ind] - 1] - pre_ascii_sum[first[ind]];
                if(sum!=0)    ans.push_back(sum);
            }
        }
        
        
        return ans;
    }
};