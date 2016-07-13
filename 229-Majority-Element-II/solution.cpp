class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0) return res;
        int count1 = 0, candidate1 = 0;
        int count2 = 0, candidate2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[candidate1]) count1++;
            else if(nums[i] == nums[candidate2]) count2++;
            else if(count1 == 0){ 
                candidate1 = i;
                count1 = 1;
            }else if(count2 == 0){
                candidate2 = i;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        int i = 0;
        count1 = 0, count2 = 0;
        while(i < nums.size()){
            if(nums[candidate1] == nums[i]) ++count1;
            else if(nums[candidate2] == nums[i]) ++count2;
            ++i;
        }
        if(count1 > nums.size() / 3) res.push_back(nums[candidate1]);
        if(count2 > nums.size() / 3) res.push_back(nums[candidate2]);
        return res;
    }
};