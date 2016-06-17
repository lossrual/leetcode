class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map_;
        for(int i = 0; i < nums1.size(); i++)
            map_[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++){
            if(map_.find(nums2[i]) != map_.end() && --map_[nums2[i]] >= 0)
                res.push_back(nums2[i]);
        }
        return res;
    }
};