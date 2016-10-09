class Solution {
public:
    int myAtoi(string s) {
        int i = 0, base = 0;
        int sign = 1;
        while(s[i] == ' ') ++i;
        if(s[i] == '+' || s[i] == '-')
            sign = 1 - 2 * (s[i++] == '-');
        while(s[i] >= '0' && s[i] <= '9') {
            if(base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
                return sign == 1 ? INT_MAX : INT_MIN;
            base = 10 * base + s[i++] - '0';
        }
        return sign * base;
    }
    double myAtof(string str) {
        int i = 0;
        int sign = 1;
        double tmp = 10;
        double base = 0;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-'){
            sign = 1 - 2 * (str[i++] == '-');
        }
        while(str[i] >= '0' && str[i] <= '9' && str[i] != '.'){
            if(base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' == INT_MAX % 10))
                return sign == -1 ? INT_MIN: INT_MAX;
            base = 10 * base + str[i++] - '0';
        }
        i++;
        while(str[i] >= '0' && str[i] <= '9'){
            base = base + (str[i++] - '0') / tmp;
            tmp *= 10;
        }
        return sign * base;
    } 
    
    
};