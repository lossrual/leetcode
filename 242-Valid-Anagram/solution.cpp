class Solution {
public:
/*
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
//有效的变位词
    bool isAnagram(string s, string t){
        if(s.length() != t.length())    return false;
        unordered_map<char, int> mps;
        for(int i = 0; i < s.length(); i++){
            mps[s[i]]++;
            mps[t[i]]--;
        }
        for(auto mp : mps){
            if(mp.second) return false;
        }
        return true;
    }
};