class Solution {
public:
/*
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() == 0) return res;
        int low = 0, high = nums.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                if(nums[mid - 1] != target){
                    res.push_back(mid);
                    while(nums[mid + 1] == target) ++mid;
                    res.push_back(mid);
                }else{
                    int tmp = mid - 1;
                    if(tmp == 0 && nums[tmp] == target) res.push_back(tmp);
                    else{ 
                        while(nums[tmp] == target) tmp--;
                        res.push_back(tmp);
                    }
                    if(mid == nums.size() - 1 && nums[mid] == target) res.push_back(mid);
                    else{
                        while(nums[mid] == target) ++mid;
                        res.push_back(mid);
                    }
                }
                return res;
            }else{
                if(nums[mid] > target){
                    high = mid;
                }else{
                    low = mid + 1;
                }
            }
        }
        return vector<int>{-1, -1};
    }
    */
     vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> res;
         if(nums.size() == 0) return res;
         int low = 0, high = nums.size() - 1;
         int left, right;
         while(low <= high){
             int mid = (low + high) / 2;
             if(nums[mid] >= target){
                 high = mid - 1;
             }else{
                 low = mid + 1;
             }
         }
         left = low;
         low = 0, high = nums.size() - 1;
         while(low <= high){
             int mid = (low + high) / 2;
             if(nums[mid] > target){
                 high = mid - 1;
             }else{
                 low = mid + 1;
             }
         }
         right = low;
         return right == left ? vector<int>{-1, -1} : vector<int>{left, right - 1}; 
     }
    
};