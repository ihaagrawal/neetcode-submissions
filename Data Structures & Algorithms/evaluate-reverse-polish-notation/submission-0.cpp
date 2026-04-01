class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();

                if (t == "+") st.push(y + x);
                else if (t == "-") st.push(y - x);
                else if (t == "*") st.push(y * x);
                else st.push(y / x);
            } else st.push(stoi(t)); 
        }

        return st.top();
    }
};