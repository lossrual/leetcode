class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
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
    //O(nlogn)
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int begin = 1, end = nums.size() - 1;
        while(begin < end){
            int mid = (begin + end) / 2;
            int count = 0;
            for(int num: nums){
                if(num <= mid)
                    ++count;
            }
            if(count > mid){
                end = mid;
            }else{
                begin = mid + 1;
            }
        }
        return begin;
    }
};