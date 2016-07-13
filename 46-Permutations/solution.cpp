class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums)){
            res.push_back(nums);
        }
        return res;
    }
    
    bool next_permutation(vector<int>& nums){
        //if(nums.size() == 0) return false;
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            --i;
        }
        int j = i + 1;
        if(i >= 0){
            while(j < nums.size() && nums[j] > nums[i]){
                ++j;      
            }
            --j;
            swap(nums[i], nums[j]);
        }else{
            return false;
        }
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
};