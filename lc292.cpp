class Solution {
public:

    int help(string q, string d){
        int res = 0;
        int n = q.size();

        for(int i = 0; i < n; i++){
            if(q[i] != d[i])    res++;
        }
        return res;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        int n = queries[0].size();
        for(string q : queries){
            for(string d : dictionary){
                int diff = help(q, d);
                if(diff <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};