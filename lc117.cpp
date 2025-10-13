class Solution {
public:
    bool anagram(string a, string b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1; i < n; i++){
            if(! anagram(words[i], ans.back())){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};