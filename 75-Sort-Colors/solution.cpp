class Solution {
public:
//荷兰旗
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(auto c: nums) {
            if(c == 2){
                nums[two++] = 2;
            }
            if(c == 1) {
                nums[two++] = 2;
                nums[one++] = 1;
            }
            if(c == 0) {
                nums[two++] = 2;
                nums[one++] = 1;
                nums[zero++] = 0;
            }
        }
    }
};