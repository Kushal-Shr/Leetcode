class MinStack {
public:
    vector<int> st;
    vector<int> min_st;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if (min_st.empty() || min_st.back() >= val)
        {
            min_st.push_back(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        if (st.back() == min_st.back())
        {
            min_st.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min_st.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */