class Solution {
public:
//set
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set_(nums1.begin(), nums1.end());
        for(auto a: nums2){
            if(set_.count(a)){
                res.push_back(a);
                set_.erase(a);
            }
        }
        return res;
    }
    //map time:O(n + m) space:O(m)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map_;
        for(int i = 0; i < nums1.size(); i++)
            map_[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++){
            if(map_.find(nums2[i]) != map_.end() && map_[nums2[i]] > 0){
                res.push_back(nums2[i]);
                map_[nums2[i]] = 0;
            }
        }
        return res;
    }
};