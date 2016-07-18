class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        for(int i = 0; i < haystack.size(); i++){
            int k = 0, j = i;
            while(k < needle.size() && j < haystack.size() && needle[k] == haystack[j]){
                ++k;
                ++j;
            }
            if(k == needle.size()) return i;
        }
        return -1;
    }
};