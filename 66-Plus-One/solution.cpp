class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size(), 0);
        int extra = 1, sum = 0;
        for(int i = digits.size() - 1; i >= 0; i--){
            sum = digits[i] + extra;
            extra = sum / 10;
            res[i] = sum % 10;
        }
        if(extra){
            res.insert(res.begin(), extra);
        }
        return res;
    }
};