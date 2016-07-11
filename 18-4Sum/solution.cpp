class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int cur1, cur2;
        for(int i = 0; i < nums.size(); i++){
            cur1 = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                int first = j + 1, last = nums.size() - 1;
                cur2 = cur1 - nums[j];
                while(first < last){
                    int sum  = nums[first] + nums[last];
                    if(sum < cur2) ++first;
                    else if(sum > cur2) --last;
                    else{
                        vector<int> vs(4, 0);
                        vs[0] = nums[i];
                        vs[1] = nums[j];
                        vs[2] = nums[first];
                        vs[3] = nums[last];
                        std::cout << vs[0] << vs[1] << vs[2] << vs[3] << '\n';
                        res.push_back(vs);
                        while(first < last && vs[2] == nums[first]) ++first;
                        while(first < last && vs[3] == nums[last]) --last;
                    }
                }
                while(nums[j] == nums[j + 1] && j < nums.size() - 1) ++j;
            }
            while(nums[i] == nums[i + 1] && i < nums.size() - 1) ++i;
        }
        return res;
    }
};