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
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int count = 0;
            int mid = (low + high) / 2;
            for(int num : nums){
                if(num <= mid)
                    ++count;
            }
            if(count > mid){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
    int findDuplicate2(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int slow = nums[0];
        int fast = nums[nums[0]];
        if(nums.size() > 1){
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while(fast != slow){
                fast = nums[fast];
                slow = nums[slow];
            }
        }
        return slow;
    }
};