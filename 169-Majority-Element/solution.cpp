//大于 n/2 的只有一个
class Solution {
public:
    int majorityElement2(vector<int>& nums) {
      unordered_map<int, int> mp;
      for(int i = 0; i< nums.size(); i++){
          if(++mp[nums[i]] > nums.size() / 2)
            return nums[i];
      }
      return 0;
    }
    int majorityElement1(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
    int majorityElement(vector<int>& nums){
        int count = 0, candidate = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i] == nums[candidate] ? count++ : count--;
            if(count < 0){
                candidate = i;
                count = 1;
            }
        }
        return nums[candidate];
    }
};

