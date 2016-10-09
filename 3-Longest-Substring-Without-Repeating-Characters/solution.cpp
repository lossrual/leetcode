class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxp = 0, pos = -1;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i])) {
                pos = max(pos, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxp = max(maxp, i - pos);
        }
        return maxp;
    }
};