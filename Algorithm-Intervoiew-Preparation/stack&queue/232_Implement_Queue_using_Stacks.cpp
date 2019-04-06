class MyQueue {
private:
    stack<int> A;
    stack<int> B;
public: 
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!A.empty()) {
            B.push(A.top());
            A.pop();
        }
        A.push(x);
        while(!B.empty()) {
            A.push(B.top());
            B.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int e = A.top();
        A.pop();
        return e;
    }
    
    /** Get the front element. */
    int peek() {
        return A.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty() && B.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */