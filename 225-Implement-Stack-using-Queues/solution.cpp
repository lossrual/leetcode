class Stack {
public:
    // Push element x onto stack.
    queue<int> que1;
    queue<int> que2;
    //int a;
    void push(int x) {
        que1.push(x);
        if(que1.size() == 1) return;
        int tmp = que1.front();
        que2.push(tmp);
        que1.pop();
    }

    // Removes the element on top of the stack.
    void pop() {
        while(que1.size() > 1){
            int a = que1.front();
            que2.push(a);
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
        return que1.empty();
    }
};