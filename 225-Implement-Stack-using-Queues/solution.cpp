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
            top = que1.front();
            que2.push(top);
        }
        que1.pop();
        while(!que2.empty()){
            int x = que2.front();
            que1.push(x);
        }
    }

    // Get the top element.
    int top() {
        return que1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};