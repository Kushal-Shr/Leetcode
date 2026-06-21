class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto p: s)
        {
            if (p == '(' || p == '{' || p == '[')
            {
                st.push(p);
            }

            else
            {
                if (st.empty()) return false;
                
                if ((p == ')' && st.top() == '(')   
                    || (p == '}' && st.top() == '{') 
                    || (p == ']' && st.top() == '['))
                    st.pop();

                else
                    return false;
            }
        }

        if (!st.empty())
            return false;

        return true;
    }
};