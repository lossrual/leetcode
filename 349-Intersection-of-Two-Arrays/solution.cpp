class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
};