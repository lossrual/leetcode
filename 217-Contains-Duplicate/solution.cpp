class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        unordered_map<int, int> mp;
        if(nums.size() == 0) return false;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        if(nums.size() == 0) return false;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end())
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};