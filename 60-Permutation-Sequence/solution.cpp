class Solution {
public:
/*
    string getPermutation(int n, int k) {
        string res;
        vector<vector<int>> vs;
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        helper(n, vs, nums, 0);
        vector<int> tt = vs[k - 1];
        for(auto c: tt){
            //std::cout << c;
            res += to_string(c);
        }
        return res;
    }
    void helper(int n, vector<vector<int>>& vs, vector<int>& nums, int len){
        if(nums.size() - 1 == len){
            vs.push_back(nums);
            return;
        }
        for(int i = len; i <= nums.size() - 1; i++){
            //std::cout << 1;
            swap(nums[i], nums[len]);
            helper(n, vs, nums, len + 1);
            swap(nums[i], nums[len]);
        }
    }
*/
    string getPermutation(int n, int k){
        string res;
        vector<int> factorial(n, 1);
        vector<char> nums(n, 1);
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i - 1] * i;
        }
        for(int i = 0; i < n; i++){
            nums[i] = (i + 1) + '0';
        }
        k--;
        for(int i = n; i >= 1; i--){
            int j = k / factorial[i - 1];
            k %= factorial[i - 1]; 
            std::cout << "j: " << j << "k: " << k << std::endl;
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};