class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 10, tmp = 9, unique = 9;
        if(n == 0) return 1;
        if(n == 1) return res;
        while(n-- > 1 && tmp){
            unique *= tmp;
            res += unique;
            tmp--;
        }
        return res;
    }
};