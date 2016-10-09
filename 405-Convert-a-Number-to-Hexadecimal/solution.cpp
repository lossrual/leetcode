class Solution {
public:
//十进制转16进制
    string toHex(int num) {
        if(num == 0) return "0";
        string res = "";
        vector<char> vc{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        unsigned int n = static_cast<unsigned int>(num);
        while(n) {
            res = vc[n & 15] + res;
            n >>= 4;
        }
        return res;
    }
//十进制转2进制
    string toHex1(int num) {
        if(num == 0) return "0";
        string res = "";
        vector<char> vc{'0','1'};
        unsigned int n = static_cast<unsigned int>(num);
        while(n) {
            res = vc[n & 1] + res;
            n >>= 1;
        }
        return res;
    }
};