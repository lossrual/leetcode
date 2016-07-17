class Solution {
public:
    int myAtoi(string str) {
        int i = 0, base = 0, sign = 1;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-'){
            sign = 1 - 2 * (str[i++] == '-');
        }
        while(str[i] >= '0' && str[i] <= '9'){
            if(base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
                return sign == -1 ? INT_MIN: INT_MAX;
            base = 10 * base + str[i++] - '0';
        }
        return sign * base;
    } 
};