class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int mini = 0;
        int curr = 0;

        sort(tasks.begin(), tasks.end(), cmp);
        for(int i = 0; i < n; i++){
            int act = tasks[i][0];
            int req = tasks[i][1];

            if(curr < req){
                mini += (req - curr);
                curr = req;
            }
            curr -= act;
        }

        return mini;
    }
};