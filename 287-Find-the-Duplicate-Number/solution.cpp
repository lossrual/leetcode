class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] > 1){
                return nums[i];
            }
        }
        return 0;
    }
};