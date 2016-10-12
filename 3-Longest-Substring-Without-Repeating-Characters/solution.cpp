class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0; 
        int pos = -1;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i])) {
                pos = max(pos, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxlen = max(maxlen, i - pos);
        }
        return maxlen;
    }
};