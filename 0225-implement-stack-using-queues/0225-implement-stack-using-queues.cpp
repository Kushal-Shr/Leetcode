class MyStack {
public:
    queue<int> q1;

    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        queue<int> q2;
        int n = q1.size();

        for (int i = 0; i < n - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q1.pop();

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }
    
    int top() {
        queue<int> temp;

        int ans;

        while (!q1.empty())
        {
            ans = q1.front();
            temp.push(q1.front());
            q1.pop();
        }

        while (!temp.empty())
        {
            q1.push(temp.front());
            temp.pop();
        }

        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */