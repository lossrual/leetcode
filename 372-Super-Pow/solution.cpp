class Solution {
    const int k = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int m = b.size();
        int res = 1;
        for(int i = m - 1; i >= 0; i--){
            res = res * myPow(a, b[i]) % k;
            a = myPow(a, 10);
        }
        return res;
    }
    int myPow(int x, int n){
        int res = 1;
        x %= k;
        while(n){
            if(n & 0x1) res = res * x % k;
            x = x * x % k;
            n >>= 1;
        }
        return res;
    }
};