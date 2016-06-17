class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i = 0, j = 0, k = 0;
        while(res.size() < n){
            res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));
            if(res.back() == res[i] * 2) ++i;
            if(res.back() == res[j] * 3) ++j;
            if(res.back() == res[k] * 5) ++k;
        }
        return res.back();
    }
private:
    bool check(int num){
        if(num == 1) return true;
        if(num == 0) return false;
        if(num %2 == 0) num /= 2;
        if(num %3 == 0) num /= 3;
        if(num %5 == 0) num /= 5;
        return num == 1;
    }
};