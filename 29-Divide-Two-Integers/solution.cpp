class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend == 0 && divisor != 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend < 0)^(divisor < 0)) ? -1 : 1;
        int digit = 0;
        long long dvd = labs(dividend), dvs = labs(divisor);
        while(dvs <= (dvd >> 1)){
            dvs <<= 1;
            ++digit;
        }
        int res = 0;
        while(digit >= 0){
            if(dvd >= dvs){
                res += 1<<digit;
                dvd -= dvs;
            }
            dvs >>= 1;
            --digit;
        }
        return sign < 0? -res : res; 
    }
};