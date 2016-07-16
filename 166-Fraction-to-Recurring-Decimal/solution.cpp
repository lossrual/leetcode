class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string res;
        if(n == 0) return "0";
        if((n < 0) ^ (d < 0)) res += '-';
        long nn = labs((long)n); long dd = labs(long(d));
        long zhengshu = nn / dd;
        res += to_string(zhengshu);
        long r = nn % dd;
        if(r == 0) return res;
        res += '.';
        r *= 10;
        unordered_map<long, long> mp;
        while(r){
            long tmp = r / dd;
            if(mp.find(r) != mp.end()){
                res.insert(mp[r], 1, '(');
                res += ')';
                break;
            }
            mp[r] = res.size();
            res += to_string(tmp);
            r = (r % dd) * 10;
        }
        return res;
    }
    string fractionToDecimal1(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};