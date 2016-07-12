class Solution {
public:
    int findPeakElement1(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1])
                return i - 1;
        }
        return nums.size() - 1;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid1, mid2;
        while(start < end){
            mid1 = (start + end) / 2;
            mid2 = mid1 + 1;
            if(nums[mid1] < nums[mid2]){
                start = mid2;
            }else{
                end = mid1;
            }
        }
        return start;
    }
    int findPeakElement2(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end){
        if(start == end) return start;
        else{
            int mid1 = (start + end) / 2, mid2 = mid1 + 1;
            if(nums[mid1] < nums[mid2]) return helper(nums, mid2, end);
            else return helper(nums, start, mid1);
        }
    }
};