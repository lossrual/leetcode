class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int reach = 0, lastreach = 0, step = 0;
        for(int i = 0; i <= reach && i < nums.size(); i++){
            if(i > lastreach){
                step++;
                lastreach = reach;
            }
            reach = max(reach, nums[i] + i);
        }
        if(reach < nums.size() - 1) return 0;
        return step;
    }
};