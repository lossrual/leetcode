class Solution {
public:
//two pass
    void sortColors1(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(auto c: nums){
            if(c == 0) ++red;
            else if(c == 1) ++white;
            else ++blue;
        }
        for(int i = 0; i < nums.size(); i++){
            if(red > 0){
                nums[i] = 0;
                --red;
                continue;
            }
            if(white > 0){
                nums[i] = 1;
                --white;
                continue;
            }
            nums[i] = 2;
        }
    }
    //one pass
    void sortColors2(vector<int>& nums) {
        int two = 0, one = 0, zero = 0;
        for(auto c: nums){
            if(c == 2){
                nums[two++] = 2;
            }else if(c == 1){
                nums[two++] = 2;
                nums[one++] = 1;
            }else{
                nums[two++] = 2;
                nums[one++] = 1;
                nums[zero++] = 0;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[i++], nums[left++]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[right--]);
            }else{
                i++;
            }
        }
    }
};