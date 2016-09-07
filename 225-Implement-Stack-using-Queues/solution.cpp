class Stack {
public:
    // Push element x onto stack.
    queue<int> que1;
    queue<int> que2;
    int count = 0;
    void push(int x) {
        que1.push(x);
        count++;
       
    }

    // Removes the element on top of the stack.
    void pop() {
        while(count > 1){
            que2.push(que1.front());
            que1.pop();
            count--;
        }
        que1.pop();
        count--;
        while(!que2.empty())
        {
            que1.push(que2.front());
            que2.pop();
            count++;
        }
    }

    // Get the top element.
    int top() {
        return que1.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty();
    }
};