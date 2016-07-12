class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1;
        //int start1, start2;
        while(low < high){
            int mid = (low + high) / 2;
            int mid2 = mid + 1;
            if(nums[mid2] > nums[mid]){
                low = mid2;
            }else{
                high = mid;
            }
        }
        return low;
    }
};