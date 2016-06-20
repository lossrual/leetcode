/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> mystack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int len = nestedList.size();
        for(int i = len - 1; i >= 0; i--){
            mystack.push(nestedList[i]);
        }
    }

    int next() {
        int tmp = mystack.top().getInteger();
        mystack.pop();
        return tmp;
    }

    bool hasNext() {
        while(!mystack.empty()){
            NestedInteger curr = mystack.top();
            if(curr.isInteger()){
                return true;
            }
            mystack.pop();
            vector<NestedInteger>& adjs = curr.getList();
            int len = adjs.size();
            for(int i = len - 1; i >= 0; i--){
                mystack.push(adjs[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */