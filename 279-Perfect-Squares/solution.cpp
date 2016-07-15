class Solution {
public:
    int numSquares(int n) {
        int count = INT_MAX;
        vector<int> vs;
        for(int i = 1; i <= n; i++){
            if(perfect_square(i))
                vs.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path, vs, n, 0);
        for(auto c: res){
            int len = c.size();
            count = min(count, len);
        }
        return count;
    }
    void helper(vector<vector<int>>& res, vector<int>& path, vector<int>& vs, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i < vs.size() && vs[i] <= target; i++){
            path.push_back(vs[i]);
            helper(res, path, vs, target - vs[i], i);
            path.pop_back();
        }
    }
    bool perfect_square(int n){
        int tmp = sqrt(n);
        return tmp * tmp == n;
    }
    int sqrt(int x){
        if(x == 0) return 0;
        if(x < 0) return INT_MIN;
        int low = 1, high = x;
        while(low < high){
            int mid = (low + high) / 2;
            if(mid > x / mid){
                high = mid;
            }else{
                low = mid + 1;
                if(mid + 1 > x / (mid + 1))
                    return mid;
            }
        }
        return low;
        
    }
};