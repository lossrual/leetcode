class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        if(nums.size() == 0) return;
        while(i < nums.size()){
            int j = 0;
            if(nums[i] == 0){
                for(j = i + 1; j < nums.size(); j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
            i++;
        }
    }
};