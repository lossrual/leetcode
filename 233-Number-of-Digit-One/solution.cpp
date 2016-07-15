class Solution {
public:
    int countDigitOne1(int n) {
        int res = 0, a = 1, b = 1;
        while(n > 0){
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            std::cout << "res:" << res << '\n';
            b += (n % 10) * a;
            std::cout << "b:" << b << '\n';
            a *= 10;
            std::cout << "a:" << a << '\n';
            n /= 10;
            std::cout << "n:" << n << '\n';
            std::cout << '\n';
        }
        return res;
    }
    int countDigitOne(int n) {
        if(n < 1) return 0;
        else if(n < 10) return 1;
        int l = 1;
        while(n / l >= 10) l *= 10;
        int r = n / l;
        int res = r * countDigitOne(l - 1) + countDigitOne(n % l);
        if(r > 1) res += l;
        else if(r == 1){
            res += (n % l) + 1;
        }
        return res;
    }
};