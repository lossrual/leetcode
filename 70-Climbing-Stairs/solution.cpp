class Solution {
public:
    int climbStairs(int n) {
        int pre = 0, cur = 1;
        while(n--) {
            int tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur;
    }
};