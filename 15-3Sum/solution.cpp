class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int sum = -nums[i];
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                int cur = nums[low] + nums[high];
                if(cur < sum) ++low;
                else if(cur > sum) --high;
                else{
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[low];
                    triplet[2] = nums[high];
                    res.push_back(triplet);
                    while(low < high && triplet[1] == nums[low]) ++low;
                    while(low < high && triplet[2] == nums[high]) --high;
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};