class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        unordered_map<char, char> start;
        start[')'] = '(';
        start['}'] = '{';
        start[']'] = '[';

        stack<char> st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(!st.empty() && st.top() == start[c]){
                    st.pop();
                }
                else    return false;
            }
        }

        return st.empty();
    }
};