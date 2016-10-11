class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[low] < nums[high]) return nums[low];
            if(nums[low] > nums[mid]){
                high = mid;
            }else{
                low = mid + 1;
            }
        } 
        return nums[low];
    }
};