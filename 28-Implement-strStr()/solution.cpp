class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() - needle.size() + 1;
        for(int i = 0; i < n; i++) {
            int k = 0, l = i;
            while(k < needle.size() && l < haystack.size() && needle[k] == haystack[l]) {
                ++k; 
                ++l;
            }
            if(k == needle.size()) return i;
        }
        return -1;
    }
};