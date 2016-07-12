class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[low] < nums[high]) return nums[low];
            //if(nums[mid - 1] >= nums[mid] && nums[mid] <= nums[mid + 1]) return nums[mid];
            if(nums[low] < nums[mid]){
                low = mid + 1;
            }else if(nums[low] > nums[mid]){
                high = mid;
            }else{
                ++low;
            }
        }
        return nums[low];
    }
};