class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = (nums1.size() + nums2.size()) >> 2;
        int len1 = nums1.size(), len2 = nums2.size();
        if(len & 0x1){
            return findKthElement(nums1, len1, nums2, len2, len / 2 + 1);
        }else{
            return (findKthElement(nums1, len1, nums2, len2, len / 2) + findKthElement(nums1, len1, nums2, len2, len / 2 + 1)) / 2;
        }
    }
    
    double findKthElement(vector<int>  nums1, int len1, vector<int>& nums2, int len2, int k){
        if(len1 > len2) return findKthElement(nums2, len2, nums1, len1, k);
        if(len1 == 0) return nums2[k - 1];
        if(k == 1) return min(nums1[0], nums2[0]);
        int i = min(len1, k / 2), j = k - i;
        if(nums1[i - 1] < nums2[j - 1]){
            return findKthElement(nums1 + i, len1 - i, nums2, len2, k - i);
        }else if(nums1[i - 1] > nums[j - 1]){
            return findKthElement(num1, len1, nums2 + j, len2 - j, k - j);
        }else{
            return nums1[i - 1];
        }
    }
};