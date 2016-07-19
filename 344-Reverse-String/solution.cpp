class Solution {
public:
    string reverseString(string s) {
        string res;
        for(int i = 0, j = s.size() - 1; i < s.size() / 2, j > i; i++, j--){
            if(s[i] == s[j]) continue;
            swap(s[i], s[j]);
        }
        res = s;
        return res;
    }
};