class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = -1, maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i])){
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};