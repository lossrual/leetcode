class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int a = num % 10;
            num /= 10;
            num += a;
        }
        return num;
    }
};