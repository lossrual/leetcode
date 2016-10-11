class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {//这里的等号尤其需要注意
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            if(nums[low] < nums[mid]) {
                if(nums[mid] > target && target >= nums[low])
                    high = mid;
                else
                    low = mid + 1;
            }else if(nums[low] > nums[mid]) {
                if(nums[high] >= target && target > nums[mid])
                    low = mid + 1;
                else 
                    high = mid;
            }else{
                low++;
            }
        }
        return false;
    }
};