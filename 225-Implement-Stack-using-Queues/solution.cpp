/*class Stack {
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
};*/


class Stack {
public:
    // Push element x onto stack.
    queue<int> que1;
    queue<int> que2;
    int count = 0;
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};