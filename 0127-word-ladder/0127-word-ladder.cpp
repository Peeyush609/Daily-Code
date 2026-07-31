class Solution {
public:
    int solve(string start, string target, unordered_set<string>& list){
        if(start == target)    return 1;

        queue<string> q;
        list.erase(start);
        q.push(start);
        int ans = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == target)  return ans;

                int len = curr.size();
                for(int i = 0; i < len; i++){
                    char ori = curr[i];
                    for(char nc = 'a'; nc <= 'z'; nc++){
                        if(nc == ori)   continue;
                        curr[i] = nc;
                        if(list.count(curr)){
                            list.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = ori;
                }
            }
            ans++;
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
        unordered_set<string> list(wordList.begin(), wordList.end());
        // check for last
        if(!list.count(endWord))    return 0;

        return solve(beginWord, endWord, list);
    }
};