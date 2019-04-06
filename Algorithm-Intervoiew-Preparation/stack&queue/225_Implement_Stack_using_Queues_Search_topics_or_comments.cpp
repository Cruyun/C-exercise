class MyStack {
private:
    deque<int> A;
public:
    /** Push element x onto stack. */
    void push(int x) {
        A.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (A.empty()) {
            return -1;
        }
        int e = A.back();
        A.pop_back();
        return e;
    }
    
    /** Get the top element. */
    int top() {
        return A.empty() ? -1 : A.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return A.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */