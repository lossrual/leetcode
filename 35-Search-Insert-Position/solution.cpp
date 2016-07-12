class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                high = mid;
            }else{
                low = mid + 1;
                //std::cout << low << std::endl;
            }
        }
        return low;
    }
};