class Stack {
public:
    // Push element x onto stack.
    queue<int> que1;
    queue<int> que2;
    int top;
    void push(int x) {
        que1.push(x);
        top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        while(que1.size() > 1){
            top = que1.top();
            que2.push(top);
        }
        que1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Get the top element.
    int top() {
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};