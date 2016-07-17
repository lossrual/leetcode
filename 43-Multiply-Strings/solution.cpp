class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if(m == 0 && n == 0) return "";
        string res(m + n, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int j = 0; j < n; j++){
            int val2 = num2[j] - '0';
            int sum = 0, extra = 0;
            for(int i = 0; i < m; i++){
                int val1 = num1[i] - '0';
                sum = val1 * val2 + res[i + j] - '0' + extra;
                //std::cout << sum << std::endl;
                res[i + j] = sum % 10 + '0';
                extra = sum / 10;
            }
            if(extra) res[j + m] = extra + '0';
        }
        reverse(res.begin(), res.end());
        int count = 0;
        while(count < res.size() - 1 && res[count] == '0') count++;
        res.erase(0, count);
        return res;
    }
};