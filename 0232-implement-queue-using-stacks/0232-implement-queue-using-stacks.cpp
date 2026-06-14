class MyQueue {
public:
    stack<int> q;
    int ele = 1;

    MyQueue() {
        
    }
    
    void push(int ele) {
        q.push(ele);
        ele++;
    }
    
    int pop() {
        stack<int> temp;
        int top;

        while (!q.empty())
        {
            top = q.top();
            temp.push(top);
            q.pop();
        }

        temp.pop();

        while (!temp.empty())
        {
            q.push(temp.top());
            temp.pop();
        }

        return top;
    }
    
    int peek() {
        stack<int> temp;
        int top;

        while (!q.empty())
        {
            top = q.top();
            temp.push(top);
            q.pop();
        }

        while (!temp.empty())
        {
            q.push(temp.top());
            temp.pop();
        }

        return top;
    }
    
    bool empty() {
        return q.empty();
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