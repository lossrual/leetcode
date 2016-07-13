class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        //int res;
        for(int i = 0; i< nums.size(); i++){
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                int cur = nums[i] + nums[low] + nums[high];
                if(cur == target) return cur;
                if(abs(cur - target) < abs(sum - target)) sum = cur;
                if(cur < target) ++low;
                else --high;
            }
        }
        return sum;
    }
};