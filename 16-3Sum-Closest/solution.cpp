class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++){
            //int cur = target - nums[i];
            int first = i + 1, last = nums.size() - 1;
            while(first < last){
                int cur = nums[first] + nums[last] + nums[i];
                if(cur == target) return target;
                if(abs(cur - target) < abs(res - target)) res = cur;
                if(cur > target) --last;
                else ++first;
            }
        }
        return res;
    }
};