

/*You are required to complete this method*/
class Solution {
  public:
    bool check (int ind, vector<int> &gas, vector<int> &cost, int n){

        int available_gas = 0;
        for(int i = 0; i < n; i ++){
            
            int k = (i + ind) % n;
            available_gas += gas[k] - cost[k];
            
            if(available_gas < 0) return false;
        }
        return true;
    }
  
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();
        
        int start = 0;
        int curr_gas = 0;
        
        for(int i = 0; i < n; i++){
            curr_gas += gas[i] - cost[i];
            
            if(curr_gas < 0){
                start = i + 1;
                curr_gas = 0;
            }
        }
        
        if(check(start, gas, cost, n))  return start;
        return -1;
    }
};


