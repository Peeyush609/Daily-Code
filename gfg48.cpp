class Solution {
  public:
    int in_Sec(string a){

        int h = stoi(a.substr(0,2));
        int m = stoi(a.substr(3,2));
        int s = stoi(a.substr(6,2));
        
        return h*60*60 + m*60 + s;
    }
  
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size();
        int ans = INT_MAX;
        
        vector<int> secs;
        
        for(int i = 0; i < n; i++){
            secs.push_back(in_Sec(arr[i]));
        }
        
        sort(secs.begin(), secs.end());
        
        for(int i = 1; i < n; i++){
            ans = min(ans, secs[i] - secs[i - 1]);
        }
        
        int last = 86400 - secs[n - 1] + secs[0];
        ans = min(ans, last);
        
        return ans;
    }
};
