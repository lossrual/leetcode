class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> vs;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = nums[i] + 1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(mp[nums[i]]) && mp[nums[i]] > 0)
                vs.push_back(mp[nums[i]]);
        }
        sort(vs.begin(), vs.end());
        return vs[0];
    }
};