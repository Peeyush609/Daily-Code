class Solution {
public:

    void binary_add(string& s){
        bool a = true;
        int n = s.size();
        reverse(s.begin(), s.end());

        for(int i = 0;i < n; i++){
            if(s[i] == '0'){
                a = false;
                s[i] = '1';
                break;
            }
            else{
                s[i] = '0';
            }
        }
        if(a)   s += '1';
        reverse(s.begin(), s.end());
    }

    int numSteps(string s) {
        int n = s.size();
        int ans = 0;

        // we have to keep play in strings
        // O(N/2) at max as after every 2 step length dec by one
        while(s != "1"){
            char last = s[s.size() - 1];
            // O(N)
            if(last == '1')     binary_add(s);
            else                s.pop_back();
            // cout<<s<<endl;
            ans++;
        }

        return ans;
    }
};