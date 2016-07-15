class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1 || n == 0) return 1;
        if(x == -1){
            return (n % 2 == 0) ? 1 : -1;
        }
        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        if(n == INT_MIN) return 0;
        return quick_pow(x, n);
    }
    double quick_pow(double x, int n){
        double res = 1;
        while(n){
            if(n & 0x1) res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }
};