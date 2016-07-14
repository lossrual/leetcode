class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend ==0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0))? -1 : 1;
        long long dvd = labs(dividend); long long dvs = labs(divisor);
        int digit = 0;
        while(dvs <= (dvd >> 1)){
            dvs <<= 1;
            ++digit;
        }
        while(digit >= 0){
            if(dvd >= dvs){
                res += 1 << digit;
                dvd -= dvs;
            }
            dvs >>= 1;
            digit--;
        }
        /*
        while(dvd >= dvs){
            long long tmp = dvs, multiple = 1;
            std::cout << "tmp: " << tmp << " " << "multiple: " << multiple << '\n';
            while(dvd >= (tmp << 1)){
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            res += multiple;
        }
        */
        return sign == 1? res : -res;
    }
};