class Solution {
public:
    int countPrimes1(int n) {
        if(n == 0 || n == 1) return 0;
        //if(n == 2) return 0;
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isprime(i))
                ++count;
        }
        return count;
    }
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        isprime[0] = false, isprime[1] = false;
        for(int i = 2; i * i < n; i++){
            if(isprime[i]){
                for(int j = i; j * i < n; j++)
                    isprime[j * i] = false;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isprime[i]){
                ++count;
            }
        }
        return count;
    }
private:
    bool isprime(int n){
        if(n == 0) return false;
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
};