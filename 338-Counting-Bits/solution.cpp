class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; i++){
            res.push_back(helper(i));
        }
        return res;
    }
    int helper(int n){
        int count = 0;
        while(n){
            n = n & (n - 1);
            ++count;
        }
        return count;
    }
};