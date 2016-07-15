class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1){
            return 0;
        }else if(n < 10){
            return 1;
        }
        int l = 1;
        while(n / l >= 10) l *= 10;
        int r = n / l;
        int res = r * countDigitOne(l - 1) + countDigitOne(n % l);
        if(r > 1){
            res += l;
        }else if(r == 1){
            res += (n % l) + 1;
        }
        return res;
    }
};