class Solution {
public:
 string fn(string s)
 {
    vector<string>temp;
   int sum=0 , start=0;
   for(int j=0;j<s.size();j++)
   {
    sum+= s[j]=='1'? 1:-1;
    if(sum==0)
    {
        string str= s.substr(start+1,j-start-1);
        temp.push_back("1"+ fn(str)+ "0");
        start=j+1;
    }
   }
   sort(temp.begin(),temp.end(),greater<string>());

   string ans="";
    for(auto m:temp)
    {
        ans+=m;
    }
    return ans;
 }
    string makeLargestSpecial(string s) {
        return fn(s);
    }
};