class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string ch: tokens)
        {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                int res = 0;

                if (ch == "+") res = y + x;
                else if (ch == "-") res = y - x;
                else if (ch == "*") res = y * x;
                else if (ch == "/") res = y / x;

                st.push(res);
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};