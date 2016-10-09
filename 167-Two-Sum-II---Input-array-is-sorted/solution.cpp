class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            if((nums[low] + nums[high]) > target)
                high--;
            else if((nums[low] + nums[high]) < target)
                low++;
            else
                return vector<int>{low + 1, high + 1};
        }
        return vector<int>{};
    }
};