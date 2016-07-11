class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return res;
        int first = 0, last = 0, target = 0, sum;
        //unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            target = -nums[i];
            first = i + 1, last = nums.size() - 1;
            while(first < last){
                sum = nums[first] + nums[last];
                if(sum < target) ++first;
                else if(sum > target) --last;
                else{
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[first];
                    triplet[2] = nums[last];
                    res.push_back(triplet);
                    while(first < last && triplet[1] == nums[first]) ++first;
                    while(first < last && triplet[2] == nums[last]) --last;
                }
            }
            while(nums[i] == nums[i + 1] && i < nums.size() - 1) ++i;
        }
        return res;
    }
};