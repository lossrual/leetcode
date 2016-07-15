class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int a = 0;
        int n = x;
        while(x){
            a = a * 10 + x % 10;
            x /= 10;
        }
        std::cout << a;
        return n == a;
    }
};