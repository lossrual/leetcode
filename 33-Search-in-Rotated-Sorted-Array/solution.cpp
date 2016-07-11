class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int low = 0, high = nums.size();
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid;
                }else{
                    low = mid + 1;
                }
            }else{
                if(nums[high - 1] >= target && target > nums[mid]){
                    low = mid + 1;
                }else{
                    high = mid;
                }
            }
        }
        return -1;
    } 
};