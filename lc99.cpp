class Solution {
public:
    int compareVersion(string version1, string version2) {
        string a;
        string b;

        vector<int> num1;
        vector<int> num2;

        for(char c: version1){
            if(c == '.'){
                num1.push_back(stoi(a));
                a = "";
            }
            else{
                a += c;
            }
        }
        if(!a.empty())   num1.push_back(stoi(a));

        for(char c: version2){
            if(c == '.'){
                num2.push_back(stoi(b));
                b = "";
            }
            else{
                b += c;
            }
        }

        if(!b.empty())   num2.push_back(stoi(b));

        for(int x: num1){cout<<x<<" ";}
        cout<<endl;
        for(int x: num2){cout<<x<<" ";}

        int m = num1.size();
        int n = num2.size();
        int i = 0;
        while(i < m || i < n){
            int p,q;
            if(i >= m){
                p = 0;
            }
            else{
                p = num1[i];
            }
            if(i >= n){
                q = 0;
            }
            else{
                q = num2[i];
            }

            if(p > q){
                return 1;
            }        
            if(q > p){
                return -1;
            }

            i++;
        }
        return 0;
    }
};