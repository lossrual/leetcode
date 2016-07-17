class Solution {
public:
    bool isHappy(int n) {
        if(n == 0) return false;
        int slow = square(n);
        int fast = square(square(n));
        while(slow != fast){
            slow = square(slow);
            fast = square(square(fast));
        }
        return slow == 1;
    }
    int square(int n){
        int sum = 0;
        while(n){
            int tmp = n % 10;
            n /= 10;
            sum += tmp * tmp;
        }
        return sum;
    }
};