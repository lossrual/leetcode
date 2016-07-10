class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() == 0) return res;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int other = target - nums[i];
            if(mp.find(other) != mp.end()){
                res.push_back(mp[other]);
                res.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};