class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        int ans=0;
        if(arr.size()==0 || arr.size()==1)  return ans;
        //simple concept is: ALWAYS TAKE THE MIN 2 ELEMENTS AND
        // ADD THEIR SUM TO ANS AND REMOVE THEM AND ADD THE ANS TO THE HEAP
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int x: arr){
            minheap.push(x);
        }
        
        while( ! (minheap.size()==1)){
            int a=minheap.top();
            minheap.pop();
            int b=minheap.top();
            minheap.pop();
            
            int cost = a + b;
            
            ans+= cost;
            minheap.push(cost);
        }
        
        return ans;
    }
};
