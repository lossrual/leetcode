class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res = helper(primes, n);
        return res[n - 1];
    }
    vector<int> helper(vector<int>& primes, int n){
        vector<int> res(n, INT_MAX);
        res[0] = 1; 
        int k = primes.size();
        vector<int> idx(k, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                res[i] = min(res[i], res[idx[j]] * primes[j]);
            }
            for(int j = 0; j < k; j++){
                idx[j] += (res[i] == res[idx[j]] * primes[j]);
            }
        }
        return res;
    }
};