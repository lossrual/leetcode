class Solution {
public:
//f(k) = f(k - 1) + 9*9*8*7*...
    int countNumbersWithUniqueDigits(int n) {
        int res = 10;
        int uniquenum = 9;
        int availablenum = 9;
        if(n == 0) return 1;
        while(n-- > 1 && availablenum > 0){
            uniquenum = uniquenum * availablenum;
            res += uniquenum;
            availablenum--;
        }
        return res;
    }
};