class MyQueue {
public:
    stack<int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int ele;
        int ans;
        stack<int> temp;

        while (!st.empty())
        {
            ele = st.top();
            st.pop();
            temp.push(ele);
        }

        ans = ele;
        temp.pop();

        while (!temp.empty())
        {
            ele = temp.top();
            temp.pop();
            st.push(ele);
        }

        return ans;
    }
    
    int peek() {
        int ele;
        int ans;
        stack<int> temp;

        while (!st.empty())
        {
            ele = st.top();
            st.pop();
            temp.push(ele);
        }

        ans = ele;

        while (!temp.empty())
        {
            ele = temp.top();
            temp.pop();
            st.push(ele);
        }

        return ans;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */