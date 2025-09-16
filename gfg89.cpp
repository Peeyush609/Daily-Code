class Solution {
  public:
    int divide(int a, int b) {
        int q = a / b;
        int r = a % b;
        if ((a ^ b) < 0 && r != 0) {
            q -= 1;  // adjust for floor division
        }
        return q;
    }
  
    int evaluatePostfix(vector<string>& arr) {
        // code here
        int n = arr.size();

        stack<int> st;
        
        for(string s: arr){
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (s == "+") st.push(b + a);
                else if (s == "-") st.push(b - a);
                else if (s == "*") st.push(b * a);
                else if (s == "/") st.push(divide(b, a));  // assuming no divide by 0
                else st.push(pow(b, a));            // fixed exponentiation
            }
            else{
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};