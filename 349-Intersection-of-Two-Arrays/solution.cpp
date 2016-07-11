class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_set<int> st(nums1.begin(), nums1.end());
        for(auto& a: nums2){
            if(st.count(a)){
                res.push_back(a);
                st.erase(a);
            }
        }
        return res;
    }
};