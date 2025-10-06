class CustomStack {
public:
    int *arr;
    int size;
    int top;
    CustomStack(int maxSize) {
        this->size = maxSize;
        arr = new int[maxSize];
        top = -1;
    }
    
    void push(int x) {
        if (top < size - 1)
        {
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if (top >= 0)
        {
            int ele = arr[top];
            top--;
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i <= top; i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */