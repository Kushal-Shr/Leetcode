class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.empty())
            return 0;
        
        stack<int> st1;
        stack<int> st2;

        for (char ch: s)
        {
            if (ch == '(')
                st1.push(ch);
            
            else
            {
                if (st1.empty())
                    st2.push(ch);
                else
                    st1.pop();
            }
        }

        return st1.size() + st2.size();
    }
};

// // we can have 2 stacks
// first one to store open paranthesis
// second one to store close paranthesis is the open is empty