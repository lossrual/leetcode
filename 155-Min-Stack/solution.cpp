//class MinStack {
//public:
//    /** initialize your data structure here. */
/*    stack<int> s1;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= getMin()) s2.push(x);
    }
    
    void pop() {
        if(s1.top() <= getMin()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
*/

//实现一个最小栈,push,pop,top,min都是O(1)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> s1;
    MinStack() {}
    void push(int x) {
        int minp;
        if(s1.empty()) {
            minp = x;
        }else {
            minp = min(s1.top().second, x);
        }
        s1.push({x, minp});
    }
    void pop() {
        s1.pop();
    }
    int top() {
        return s1.top().first;
    }
    int getMin() {
        return s1.top().second;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */